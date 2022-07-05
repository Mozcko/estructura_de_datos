#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

char FIGURAS[4][20]= {"CORAZONES","TRÉBOLES","ESPADAS","DIAMANTES"};

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
struct carta extraer();
void liberar();
void aleatoria(int n);
void menu();

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;

void insertar(struct carta x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = x;
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
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

struct carta extraer()
{
    if (raiz != NULL)
    {
        struct carta informacion = raiz->info;//respaldar info
        struct nodo *bor = raiz;
        raiz = raiz->sig;
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
    int op,n;
    struct carta c1;
    while(op != 5)
    {

        system("cls");
        printf("Selecciona la opción deseada\n"
               "\t1\tInsertar Carta\n"
               "\t2\tImprimir Cartas\n"
               "\t3\tBorrar Carta\n"
               "\t4\tCarta Aleatoria\n"
               "\t5\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
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

            c1=extraer();
            printf("se borro %i de %s \n", c1.num, c1.figura);

            break;
        case 4:
            printf("Cuantas cartas deseas generar ?\n");
            scanf("%i",&n);
            aleatoria(n);
            break;
        case 5:
            liberar();
            printf("Adios \n");
            break;
        default:
            printf("Opción Incorrecta \n");

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

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}