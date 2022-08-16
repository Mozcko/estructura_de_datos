#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

void insertar(int x);
int vacia();

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

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

int main(){

    insertar(7);
    insertar(10);
    insertar(8);
    insertar(9);
    insertar(3);
    insertar(8);
    insertar(4);
    insertar(5);


    struct nodo *reco2=fondo;
    struct nodo *reco=raiz->sig; 
    for(int i=0; i<4; i++) 
    {
        reco=reco->sig;
    } 
    printf("%i, %i \n", (reco2->info)+2,( reco->info)+2);
}