#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};


void insertar(int x);
int extraer();
void imprimir();
void liberar();
int vacia();
void menu();
void modificar();
int cantidad();



struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

void insertar(int x)
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

int extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
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
    else
        return -1;
}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL)
    {
        printf("%i - ", reco->info);
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
    int op,x;
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
            scanf("%i",&x);
            insertar(x);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            x= extraer();
            printf("Se borro el dato %i \n",x);
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
    int info, pos;
    struct nodo *reco=raiz;
    printf("Que posiciÃ³n quiere cambiar ?\n");
    scanf("%i",&pos);
    if(pos > cantidad() || pos < 1){
        return;
    }else{
          printf("Cual es el nuevo valor ?\n");
          scanf("%i",&info);
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