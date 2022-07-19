#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

struct nombre{
    char nom[20];
};

struct nodo {
    struct nombre info;
    struct nodo *sig;
};


void insertar(struct nombre x);
struct nombre extraer();
void imprimir();
void liberar();
int vacia();
void menu();
void modificar();
int cantidad();



struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

void insertar(struct nombre x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    nuevo->sig=NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

struct nombre extraer()
{
    if (!vacia())
    {
        struct nombre informacion = raiz->info;
        struct nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->sig;
        }
        free(bor);
        return informacion;
    }

}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL)
    {
        printf("%s - ", reco->info.nom);
        reco = reco->sig;
    }
    printf("\n");
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

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void menu()
{
    struct nombre x;
    int op;
    while(op != 5)
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tInsertar Nuevo nodo\n"
               "\t2\tImprimir Lista\n"
               "\t3\tBorrar Nodo\n"
               "\t4\tModificar Nodo\n"
               "\t5\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            printf("Que valor deseas insertar ? \n");
            fflush(stdin);
            gets(x.nom);
            insertar(x);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            x= extraer();
            printf("Se borro el nombre %s \n",x.nom);
            break;
        case 4:
            modificar();
            break;
        case 5:
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
    struct nombre info;
    int pos;
    struct nodo *reco=raiz;
    printf("Que posiciÃ³n quiere cambiar ?\n");
    scanf("%i",&pos);
    if(pos > cantidad() || pos < 1){
        return;
    }else{
          printf("Cual es el nuevo valor ?\n");
          fflush(stdin);
          gets(info.nom);
          for(int i=1; i<pos; i++){
            reco= reco->sig;
          }
          reco->info = info;
    }
    return;

}

int main()
{
    menu();
    return 0;
}