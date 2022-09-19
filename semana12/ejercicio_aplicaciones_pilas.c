#include <stdio.h>
#include <stdlib.h>

struct cuenta{
    int dinero;
    int log;
};

struct nodo{
    int info;
    struct nodo *next;
};

struct nodo *root = NULL;
struct nodo *last = NULL;

int vacia(){
    if (root == NULL)
        return 1;
    else
        return 0;
}

void menu()
{
    int op, val, pos;
    while (op != 5)
    {
        system("clear");
        printf("Selecciona la opción deseada\n"
               "\t1\tDepositar dinero\n"
               "\t2\tRetirar dinero\n"
               "\t3\tDinero Actual\n"
               "\t4\tLista de transacciones\n"
               "\t5\tSalir \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Opción Incorrecta \n");
        }
        system("read -n 1 -s -p \"Press any key to continue...\"");
    }
    return;
}

int main(){
    menu();
    return 0;
}