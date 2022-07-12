#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
    char info[20];
    struct nodo *sig;
};

void insertar(char *x);
void extraer();
int vacia();
void imprimir();
void liberar();
void modificar();
int cantidad();

struct nodo *raiz = NULL;
struct nodo *fondo = NULL;

// uso de strcpy

void insertar(char *x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    strcpy(nuevo->info, x);
    nuevo->sig = NULL;
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

void extraer()
{
    if (!vacia())
    {
        char informacion[20];
        strcpy(informacion, raiz->info);
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
        printf("se borro el dato %s", informacion);
    }
    else
    {
        return;
    }
}

void imprimir()
{
    struct nodo *reco = raiz;
    printf("Listado de elementos de la cola \n");
    while (reco != NULL)
    {
        printf(" %s - ", reco->info);
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

int cantidad()
{
    int n;
    struct nodo *reco = raiz;
    if (vacia())
    {
        n = 0;
    }
    else
    {
        while (reco != NULL)
        {
            n++;
        }
    }
    return n;
}

void modificar()
{
    int pos, i;
    char info[20];
    struct nodo *reco = raiz;
    printf("que posición desea modificar?\n");
    scanf("%i", &pos);
    if (pos > cantidad() || pos < 1)
    {
        printf("posición no valida");
        return;
    }
    else
    {
        printf("¿cual es el nuevo valor del nodo %i?", pos);
        gets(info);
        for (i = 0; i < pos - 1; i++)
        {
            reco = reco->sig;
        }
        *reco->info = *info;
    }
}

void menu()
{
    int op;
    char x[20];
    while (op != 5)
    {

        system("cls");
        printf("Selecciona la opción deseada\n"
               "\t1\t Insertar Nuevo Nodo\n"
               "\t2\t Imprimir Lista\n"
               "\t3\t Borrar Nodo\n"
               "\t4\t Modificar Nodo\n"
               "\t5\t Salir\n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            printf("inserte el numero que quiera añadir\n");
            gets(x);
            insertar(x);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            extraer();
            break;
        case 4:
            modificar();
            break;
        case 5:
            liberar();
            printf("Adios \n");
            break;
        default:
            printf("Opción Incorrecta o No Valida \n");
        }
        system("pause");
    }
    return;
}

int main()
{
    menu();
    return 0;
}