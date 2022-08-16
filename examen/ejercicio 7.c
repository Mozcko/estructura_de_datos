#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//generica doblemente encadenada

struct nodo {
    int info;
    struct nodo *sig;
    struct nodo *ant;
};

struct nodo *raiz=NULL;


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
    struct nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void imprimir()
{
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    while (reco!=NULL)
    {
        printf("%i ",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}


void insertar(int pos, int x)
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

int extraer(int pos)
{
    if (pos <= cantidad())
    {
        int informacion;
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
    else
        return -1;
}

void borrar(int pos)
{
    if (pos <= cantidad())
    {
        struct nodo *bor;
        if (pos == 1)
        {
            bor = raiz;
            raiz = raiz->sig;
            if (raiz != NULL)
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
        }
        free(bor);
    }
}


void intercambiar(int pos1, int pos2)
{
    if (pos1 <= cantidad() && pos2 <= cantidad())
    {
        struct nodo *reco1 = raiz;
        int f;
        for (f = 1; f < pos1; f++)
        {
            reco1 = reco1->sig;
        }
        struct nodo *reco2 = raiz;
        for (f = 1; f < pos2; f++)
        {
            reco2 = reco2->sig;
        }
        int aux = reco1->info;
        reco1->info = reco2->info;
        reco2->info = aux;
    }
}

int mayor()
{
    if (!vacia())
    {
        int may = raiz->info;
        struct nodo *reco = raiz->sig;
        while (reco != NULL)
        {
            if (reco->info > may)
            {
                may = reco->info;
            }
            reco = reco->sig;
        }
        return may;
    }
    else
        return -1;
}


int posMayor()
{
    if (!vacia())
    {
        int may = raiz->info;
        int x = 1;
        int pos = x;
        struct nodo *reco = raiz->sig;
        while (reco != NULL)
        {
            if (reco->info > may)
            {
                may = reco->info;
                pos = x;
            }
            reco = reco->sig;
            x++;
        }
        return pos;
    }
    else
        return -1;
}

int ordenada()
{
    if (cantidad()>1)
    {
        struct nodo *reco1 = raiz;
        struct nodo *reco2 = raiz->sig;
        while (reco2 != NULL)
        {
            if (reco2->info<reco1->info)
            {
                return 0;
            }
            reco2 = reco2->sig;
            reco1 = reco1->sig;
        }
    }
    return 1;
}

int existe(int x)
{
    struct nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->info == x)
            return 1;
        reco = reco->sig;
    }
    return 0;
}


int main()
{
    insertar(1,1);
    insertar(2,2);
    insertar(3,7);
    insertar(4,7);
    insertar(5,8);
    insertar(6,9);
    insertar(7,3);
    insertar(8,8);
    insertar(9,4);
    insertar(10,5);

    struct nodo *reco2;
    struct nodo *reco=raiz->sig; for(int i=0; i<3; i++) { reco2 = reco->ant; reco=reco->sig;} printf("%i, %i \n", reco->info, reco2->info);
    return 0;
}