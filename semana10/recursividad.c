#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 6

float vec[CANTIDAD];
float *pi = vec;

void cargar(float vec[CANTIDAD]);
void ordenar(float vec[CANTIDAD], int cant);
void imprimir(float vec[CANTIDAD]);
void menu();

void cargar(float vec[CANTIDAD])
{
    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("ingrese la estatura %i: ", i + 1);
        scanf("%f", &vec[i]);
    }
}

void ordenar(float vec[CANTIDAD], int cant)
{
    if (cant > 1)
    {
        for (int i = 0; i < cant - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                float aux = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = aux;
            }
        }
        ordenar(vec, cant - 1);
    }
}

void imprimir(float vec[CANTIDAD])
{
    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("%.2f ", vec[i]);
    }
    printf("\n");
}

void menu()
{
    int op;
    while (op != 4)
    {
        system("clear");
        printf("Selecciona la opción deseada\n"
               "\t1\tPedir Estaturas\n"
               "\t2\tOrdenar\n"
               "\t3\tImprimir\n"
               "\t4\tSalir \n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            cargar(pi);
            break;
        case 2:
            ordenar(pi, CANTIDAD);
            break;
        case 3:
            imprimir(pi);
            break;
        case 4:
            printf("adios\n");
            break;
        default:
            printf("Opción Incorrecta \n");
        }
        //system("pause");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
    }
    return;
}

int main(int argc, char **argv)
{
    menu();
    return 0;
}