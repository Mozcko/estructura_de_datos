#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

char FIGURAS[4][20]= {"CORAZONES","TREBOLES","ESPADAS","DIAMANTES"};

struct carta
{
    char figura[20];
    int num;
};

struct nodo
{
    struct carta info;
    struct nodo *sig;
    struct nodo *ant;
};

void insertar(int pos, struct carta x);
void imprimir();
void reversa();
struct carta extraer(int pos);
void liberar();
void aleatoria(int n);
void menu();

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;
struct nodo *fondo=NULL;


void insertar(int pos, struct carta x)
{
    if (pos <= cantidad() + 1)
    {
        struct nodo *nuevo;
        nuevo=malloc(sizeof(struct nodo));
        nuevo->info = x;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        if (pos == 1)
        {
            nuevo->sig = raiz;
            if (raiz != NULL)
                raiz->ant = nuevo;
            raiz = nuevo;
        }
        else
            if (pos == cantidad() + 1)
            {
                struct nodo *reco = raiz;
                while (reco->sig != NULL)
                {
                    reco = reco->sig;
                }
                reco->sig = nuevo;
                nuevo->ant = reco;
            }
            else
            {
                struct nodo *reco = raiz;
                int f;
                for (f = 1; f <= pos - 2; f++)
                    reco = reco->sig;
                struct nodo *siguiente = reco->sig;
                reco->sig = nuevo;
                nuevo->ant = reco;
                nuevo->sig = siguiente;
                siguiente->ant = nuevo;
            }
    }
}


int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void imprimir()
{
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    while (reco!=NULL)
    {
        printf("%i de %s \n",reco->info.num, reco->info.figura);
        reco=reco->sig;
    }
    printf("\n");
}


void reversa()
{
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    for(int i=0; i<cantidad()-1; i++)
    {
        reco=reco->sig;
    }
    for(int i=0; i<cantidad(); i++)
    {
        printf("%i de %s \n",reco->info.num, reco->info.figura);
        reco=reco->ant;
    }

    printf("\n");
    return;
}

struct carta extraer(int pos)
{
    if (pos <= cantidad())
    {
        struct carta informacion;
        struct nodo *bor;
        if (pos == 1)
        {
            informacion = raiz->info;
            bor = raiz;
            raiz = raiz->sig;
            if ((raiz != NULL))
                raiz->ant = NULL;
        }
        else
        {
            struct nodo *reco;
            reco = raiz;
            int f;
            for (f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            struct nodo *prox = reco->sig;
            bor = prox;
            reco->sig = prox->sig;
            struct nodo *siguiente = prox->sig;
            if (siguiente != NULL)
                siguiente->ant = reco;
            informacion = prox->info;
        }
        free(bor);
        return informacion;
    }

}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}


void menu()
{
    int op,n, pos;
    struct carta c1;
    while(op != 7)
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tInsertar Carta\n"
               "\t2\tImprimir Cartas\n"
               "\t3\tBorrar Carta\n"
               "\t4\tCarta Aleatoria\n"
               "\t5\tModificar Carta \n"
               "\t6\tImprimir desde el fin de la lista \n"
               "\t7\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            printf("Escribe la posicion de la carta \n");
            scanf("%i",&pos);
            printf("Escribe la figura de la carta \n");
            fflush(stdin);
            gets(c1.figura);
            printf("Escribe el numero de la carta \n");
            scanf("%i",&c1.num);
            insertar(pos, c1);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            printf("Escribe la posicion de la carta \n");
            scanf("%i",&pos);
            c1=extraer(pos);
            printf("se borro %i de %s \n", c1.num, c1.figura);

            break;
        case 4:
            printf("Cuantas cartas deseas generar ?\n");
            scanf("%i",&n);
            aleatoria(n);
            break;

        case 5:
            modificar();
            break;

        case 6:
            reversa();
            break;
        case 7:
            liberar();
            printf("Adios \n");
            break;
        default:
            printf("Opcion Incorrecta \n");

        }
        system("pause");
    }
    return;
}


void aleatoria(int n)
{
    struct carta c;
    for(int i=0; i<n; i++)
    {
        c.num = rand()%13 + 1;
        strcpy(c.figura,FIGURAS[rand()%4]);
        insertar(1,c);
    }
    return;
}


int cantidad()
{
    int n=0;
    struct nodo *reco = raiz;
    if(vacia()){
        return n;
    }
    else{
        while(reco != NULL)
        {
            n++;
            reco= reco->sig;
        }
        return n;
    }
}

void modificar()
{
    struct carta info;
    int pos;
    struct nodo *reco=raiz;
    printf("Que posiciÃƒÆ’Ã‚Â³n quiere cambiar ?\n");
    scanf("%i",&pos);
    if(pos > cantidad() || pos < 1){
        return;
    }else{
          printf("Cual es el nuevo valor de la figura?\n");
          fflush(stdin);
          gets(info.figura);
          printf("Cual es el numero de la carta?\n");
          scanf("%i",&info.num);
          for(int i=1; i<pos; i++){
            reco= reco->sig;
          }
          reco->info = info;
    }
    return;

}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}