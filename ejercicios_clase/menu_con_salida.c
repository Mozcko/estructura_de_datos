#include <stdio.h>
#include <stdlib.h>

void menu2();
void f1();
void f2();
void f3();
void f4();

int main()
{
    menu2();
    return 0;
}


void menu2()
{
    int op;
    while(op != 5)
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tFuncion 1\n"
               "\t2\tFuncion 2\n"
               "\t3\tFuncion 3\n"
               "\t4\tFuncion 4\n"
               "\t5\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        case 3:
            f3();
            break;
        case 4:
            f4();
            break;
        case 5:
            printf("Adios \n");
            break;
        default:
            printf("Opcion Incorrecta \n");

        }
        system("pause");
    }
    return;
}

void f1()
{
    printf("Estas en la funcion 1 \n");
    return;
}

void f2()
{
    printf("Estas en la funcion 2 \n");
    return;
}

void f3()
{
    printf("Estas en la funcion 3 \n");
    return;
}

void f4()
{
    printf("Estas en la funcion 4 \n");
    return;
}