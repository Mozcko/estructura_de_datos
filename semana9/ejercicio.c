#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    char info[20];
    struct nodo *next;
};

struct nodo *root = NULL;
struct nodo *end =NULL;

int empty(){
    if (root == NULL) {return 1;}
    else {return 0;}
}

void insert(char *x){
    struct nodo *new;
    new = malloc(sizeof(struct nodo));
    strcpy(new->info, x);
    new->next = NULL;
    if (empty()){
        root = new;
        end = new;
    }else {
        end->next = new;
        end = new;
    }
}

char* extract(){
    if (!empty()){
        static char info[20];
        strcpy(info, root->info);
        struct nodo *bor = root;
        if(root = end){
            root = NULL;
            end = NULL;
        }
        else {
            root = root->next;
        }
        free(bor);
        return info;
    }
    else{
        return NULL;
    }
}

void print(){
    struct nodo *reco = root;
    printf("Listado de elementos en la lista\n");
    while(reco != NULL){
        printf("%s",reco->info);
        reco = reco->next;
    }
    printf("\n");
}

void freeSpace(){
    struct nodo *reco = root;
    struct nodo *bor;
    while(reco != NULL){
        bor = reco;
        reco = reco->next;
        free(bor);
    }
}

int empty(){
    
}

int main() {
    
    return 0; 
}