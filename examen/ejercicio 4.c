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



void f1(int x)
{ 
    struct nodo *nuevo; 
    nuevo = malloc(sizeof(struct nodo)); 
    nuevo->info = x;
    if (raiz == NULL)
    {
        raiz = nuevo;nuevo->sig = NULL;
    }
    else
    { 
        nuevo->sig = raiz;raiz = nuevo;
    }
}

int main(){
    f1(5);
}

