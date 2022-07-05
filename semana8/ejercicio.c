#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

struct carta{
    char figura[20];
    int num;
};

struct nodo{
    struct carta info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;



int main(int argc, char **argv){
    
    return 0;
}