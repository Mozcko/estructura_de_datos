#include <stdio.h>
//#include <conio.h>

void cargar(int vec[5]);
void imprimir(int vec[5]);

int main()
{
    int vector[5];
    cargar(vector);
    imprimir(vector);
    getch();
    return 0;
}


void cargar(int vec[5])
{
    int x;
    for(x=0;x<5;x++)
    {
        printf("Ingrese elemento:");
        scanf("%i",&vec[x]);
    }
}

void imprimir(int vec[5])
{
    int x;
    printf("Contenido completo del vector:");
    for(x=0;x<5;x++)
    {
        printf("%i ",vec[x]);
    }
}