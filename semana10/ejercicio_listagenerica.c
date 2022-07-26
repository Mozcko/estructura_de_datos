#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int info;
    struct node *next;
};

void insert(int pos, int x);
void print();
int extract(int pos);
void modify();
void freeList();
void menu();
int empty();
int cantidad();

struct node *first = NULL;
struct node *last = NULL;

void print()
{
    struct node *reco = first;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL)
    {
        printf("%s - ", reco->info);
        reco = reco->next;
    }
    printf("\n");
}

void insert(int pos, int x)
{
    if (pos <= cantidad() + 1)
    {
        struct node *new;
        new = malloc(sizeof(struct node));
        new->info = x;
        if (pos == 1)
        {
            new->next = first;
            first = new;
        }
        else
        {
            if (pos == cantidad() + 1)
            {
                struct node *reco = first;
                while (reco->next != NULL)
                {
                    reco = reco->next;
                }
                reco->next = new;
                new->next = NULL;
            }
            else
            {
                struct node *reco = first;
                for (int i = 0; i <= pos - 2; i++)
                {
                    reco = reco->next;
                }
                struct node *next = reco->next;
                reco->next = new;
                new->next = next;
            }
        }
    }
}

int extract(int pos)
{
    if (pos <= cantidad())
    {
        int informacion;
        struct node *bor;
        if (pos == 1)
        {
            informacion = first->info;
            bor = first;
            first = first->next;
        }
        else
        {
            struct node *reco;
            reco = first;
            for (int i = 1; i <= pos - 2; i++)
            {
                reco = reco->next;
            }
            struct node *prox = reco->next;
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

void modify()
{
    int pos, x;
    struct node *reco = first;
    printf("que posición desea modificar? \n");
    scanf("%i", &pos);
    if (pos > cantidad() || pos < 1)
    {
        printf("posición no valida");
        return;
    }
    else
    {
        printf("introduzca el nuevo valor para la posición %i", pos);
        scanf("%i", x);
        for (int i = 1; i < pos; i++)
        {
            reco = reco->next;
        }
        reco->info = x;
    }
    return;
}

void menu()
{
    int op, val, pos;
    while (op != 5)
    {

        system("cls");
        printf("Selecciona la opción deseada\n"
               "\t1\tInsertar valor a la lista 1\n"
               "\t2\tImprimir la lista\n"
               "\t3\tExtraer nodo de la lista\n"
               "\t4\tModificar un nodo de la lista\n"
               "\t5\tSalir \n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            printf("escribe el valor a insertar \n");
            scanf("%i", &val);
            printf("escribe donde insertar el valor\n");
            scanf("%i", &pos);
            insert(pos, val);
            break;
        case 2:
            print();
            break;
        case 3:
            printf("escribe la posición del valor a extraer \n");
            scanf("%i", &pos);
            printf("Extraemos de la pila:%i\n", extract(pos));
            break;
        case 4:
            modify();
            break;
        case 5:
            freeList();
            printf("Adios \n");
            break;
        default:
            printf("Opción Incorrecta \n");
        }
        system("pause");
    }
    return;
}

int empty()
{
    if (first == NULL && last == NULL)
        return 1;
    else
        return 0;
}

int cantidad()
{
    int n = 0;
    struct node *reco = first;
    if (empty())
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

void freeList()
{
    struct node *reco = first;
    struct node *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->next;
        free(bor);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    menu();
    return 0;
}