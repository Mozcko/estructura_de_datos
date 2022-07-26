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
};

void insertar(struct carta x);
void imprimir();
struct carta extraer(int pos);
void liberar();
void aleatoria(int n);
void menu();

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;
struct nodo *fondo=NULL;


void insertar(struct carta x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info = x;
    nuevo->sig=NULL;
    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        if (strcmp(x.figura,raiz->info.figura)<0)
        {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
        else
        {
            struct nodo *reco = raiz;
            struct nodo *atras = raiz;
            while ((strcmp(x.figura,reco->info.figura)>=0)&& reco->sig != NULL)
            {
                atras = reco;
                reco = reco->sig;
            }
            if (strcmp(x.figura,reco->info.figura)>=0)
            {
                reco->sig = nuevo;
            }
            else
            {
                nuevo->sig = reco;
                atras->sig = nuevo;
            }
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
        }
        else
        {
            struct nodo *reco;
            reco = raiz;
            int f;
            for (f = 1; f <= pos - 2; f++)
            {
                reco = reco->sig;
            }
            struct nodo *prox = reco->sig;
            reco->sig = prox->sig;
            informacion = prox->info;
            bor = prox;
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
    while(op != 6)
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tInsertar Carta\n"
               "\t2\tImprimir Cartas\n"
               "\t3\tBorrar Carta\n"
               "\t4\tCarta Aleatoria\n"
               "\t5\tModificar Carta \n"
               "\t6\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            //printf("Escribe la posicion de la carta \n");
            //scanf("%i",&pos);
            printf("Escribe la figura de la carta \n");
            fflush(stdin);
            gets(c1.figura);
            printf("Escribe el numero de la carta \n");
            scanf("%i",&c1.num);
            insertar(c1);
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
        insertar(c);
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