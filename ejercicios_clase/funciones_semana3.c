#include <stdio.h>
#include <stdlib.h>
void saluda(); // declarando la funcion saluda
void despedirse();
void menu();

int main()
{
    menu();
    menu();
    menu();
    menu();
    menu();
    return 0;
}

void saluda()
{
     printf("Bienvenido\n");
    return;
}

void despedirse()
{
    printf("Adios\n");
    return;
}

void menu()
{
    int op;
    printf("Selecciona la opcion deseada \n"
           "\t1\tSaluda \n"
           "\t2\tDespedirse"
           );
    scanf("%i",&op);
    system("cls");
    if(op == 1)
    {
        saluda();
    }
    else
    {
        if(op == 2)
        {
            despedirse();
        }
        else
        {
            printf("opcion incorrecta \n");
        }
    }
    return;
}