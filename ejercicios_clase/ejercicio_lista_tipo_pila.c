#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>


struct nodo
{
    int info;
    struct nodo *sig;
};
void insertar(int x);
void imprimir();
int extraer();
void liberar();
void mayor();
void menu();

//variable global que apunta al primer nodo de la lista
struct nodo *raiz=NULL;

void insertar(int x)
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
    return;
}

void imprimir()
{
    struct nodo *reco=raiz; // crear un apuntador hacia el primer nodo
    printf("Lista completa.\n");
    while (reco!=NULL)
    {
        printf("%i ",reco->info);
        reco=reco->sig;
    }
    printf("\n");
    return;
}

int extraer()
{
    if (raiz != NULL) // revisar si la lista tiene nodos
    {
        int informacion = raiz->info; // guarda la info del nodo a borrar
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
    }
    else
    {
        return -1;
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
    return;
}

void menu()
{
    int op,val;
    while(op != 5)
    {

        system("cls");
        printf("Selecciona la opción deseada\n"
               "\t1\tInsertar valor a la lista 1\n"
               "\t2\tImprimir la lista\n"
               "\t3\tExtraer nodo de la lista\n"
               "\t4\tMayor valor de la pila\n"
               "\t5\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            printf("escribe el valor a insertar \n");
            scanf("%i",&val);
            insertar(val);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            printf("Extraemos de la pila:%i\n",extraer());
            break;
        case 4:
            mayor();
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

void mayor()
{

    struct nodo *reco=raiz; // crear un apuntador hacia el primer nodo
    int may = raiz -> info; // guardo el primer valor de la lista

    while (reco!=NULL)
    {
        if(reco->info > may){
            may = reco -> info;
        }
        reco=reco->sig; // paso al sig nodo
    }
    printf("El valor mas grande de la lista es %i \n",may);
    return;
}

int main()
{
    menu();
    getch();
    return 0;
}