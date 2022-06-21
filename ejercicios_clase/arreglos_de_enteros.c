#include <stdio.h>
#include <stdlib.h>
#define NH  3

void    guardar_hermanos(int *ph);
void    mostrar_hermanos(int *ph);
int main()
{
    int num_hermanos[NH];
    guardar_hermanos(num_hermanos);
    mostrar_hermanos(num_hermanos);
    return 0;
}

void    guardar_hermanos(int *ph)
{
    int i;
    for(i=0; i<NH; i++)
    {
        printf("Ingresa la cantidad de hermanos de la persona %i \n",i+1);
        scanf("%i",&ph[i]);
    }
    return;
}

void   mostrar_hermanos(int *ph)
{
    int i;
    for(i=0; i<NH; i++)
    {
        printf(" la cantidad de hermanos de la persona %i es %i \n",i+1,ph[i]);
    }
    return;
}