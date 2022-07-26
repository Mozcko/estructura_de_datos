#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int info;
    struct nodo *next;
};

void liberar();
int cantidad();
int vacia();
void imprimir();
void insertar(int x);
void modificar();
int eliminar(int pos);
void menu();

struct nodo *root = NULL;

void liberar()
{
    struct nodo *reco = root;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->next;
        free(bor);
    }
}

int cantidad()
{
    int n = 0;
    struct nodo *reco = root;
    if (vacia())
    {
        return n;
    }
    else
    {
        while (reco != NULL)
        {
            n++;
            reco = reco->next;
        }
        return n;
    }
}

int vacia()
{
    if (root == NULL)
        return 1;
    else
        return 0;
}

void imprimir()
{
    struct nodo *reco = root;
    printf("Lista completa \n");
    while (reco != NULL)
    {
        printf("%i ", reco->info);
        reco = reco->next;
    }
    printf("\n");
}

void insertar(int x)
{
    struct nodo *new;
    new = malloc(sizeof(struct nodo));
    new->info = x;
    new->next = NULL;
    if (root == NULL)
    {
        root = new;
    }
    else
    {
        if (x < root->info)
        {
            new->next = root;
            root = new;
        }
        else
        {
            struct nodo *reco = root;
            struct nodo *back = root;
            while (x >= reco->info && reco->next != NULL)
            {
                back = reco;
                reco = reco->next;
            }
            if (x >= reco->info)
            {
                reco->next = new;
            }
            else
            {
                new->next = reco;
                back->next = new;
            }
        }
    }
}

void modificar()
{
    int pos, x;
    struct nodo *reco = root;
    printf("que posición desea modificar? \n");
    scanf("%d", &pos);
    if (pos > cantidad() || pos < 1)
    {
        printf("posición no valida");
        return;
    }
    else
    {
        printf("introduzca el nuevo valor para la posición %i", pos);
        scanf("%i", &x);
        for (int i = 1; i < pos; i++)
        {
            reco = reco->next;
        }
        reco->info = x;
    }
    return;
}

int eliminar(int pos)
{
    if (pos <= cantidad())
    {
        int informacion;
        struct nodo *bor;
        if (pos == 1)
        {
            informacion = root->info;
            bor = root;
            root = root->next;
        }
        else
        {
            struct nodo *reco;
            reco = root;
            for (int i = 1; i < pos - 2; i++)
            {
                reco = reco->next;
            }
            struct nodo *prox = reco->next;
            reco->next = prox->next;
            informacion = prox->info;
            bor = prox;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void menu()
{
    int op, val, pos;
    while (op != 5)
    {
        system("clear");
        printf("Selecciona la opción deseada\n"
               "\t1\tInsertar valor a la lista\n"
               "\t2\tImprimir la lista\n"
               "\t3\tExtraer nodo de la lista\n"
               "\t4\tModificar un nodo de la lista\n"
               "\t5\tSalir \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("escribe el valor a insertar \n");
            scanf("%i", &val);
            insertar(val);
            break;
        case 2:
            imprimir();
            break;
        case 3:
            printf("escribe la posición del valor a extraer \n");
            scanf("%i", &pos);
            printf("Extraemos de la pila:%i\n", eliminar(pos));
            break;
        case 4:
            modificar();
            break;
        case 5:
            liberar();
            printf("Adios \n");
            break;
        default:
            printf("Opción Incorrecta \n");
        }
        system("read -n 1 -s -p \"Press any key to continue...\"");
    }
    return;
}

int main()
{
    menu();
    return 0;
}