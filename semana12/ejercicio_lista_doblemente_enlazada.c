#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo
{
    int info;
    struct nodo *next;
    struct nodo *prev;
};

void liberar();
int cantidad();
int vacia();
void imprimir();
void insertar(int pos, int x);
void modificar();
int eliminar(int pos);
void menu();

struct nodo*root = NULL;

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

int vacia()
{
    if (root == NULL)
        return 1;
    else
        return 0;
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

void insertar(int pos, int x){
    struct nodo *new;
    new = malloc(sizeof(struct nodo));
    new->info = x;
    new->prev = NULL; 
    new->next = NULL;

    if (pos == 1){
        new->next = root;
        if (root != NULL)
            root->prev = new;
        root = new;
    }
    else{
        if (pos == cantidad() + 1){
            struct nodo *reco = root;
            while (reco->next != NULL){
                reco = reco->next;
            }
            reco->next = new;
            new->prev = reco;
        }
        else{
            struct nodo *reco = root;
            for (int i = 0; i <= pos - 2; i++)
                reco = reco->next;
            struct nodo *sig = reco->next;
            reco->next = new;
            new->prev = reco;
            new->next = sig;
            sig->prev = new;
        }
    }
}

int eliminar(int pos){
    if (pos <= cantidad()){
        int informacion;
        struct nodo *bor;
        if (pos == 1){
            informacion = root->info;
            bor = root;
            root = root->next;
            if (root != NULL)
                root->prev = NULL;
        }
        else{
            struct nodo *reco;
            reco = root;
            for (int i = 1; i <= pos - 2; i++)
                reco = reco->next;
            struct nodo *prox = reco->next;
            bor = prox;
            reco->next = prox->next;
            struct nodo *siguiente = prox->next;
            if (siguiente != NULL)
                siguiente->prev = reco;
            informacion = prox->info;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

int main(){
    return 0;
}

    