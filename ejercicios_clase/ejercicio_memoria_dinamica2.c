#include <stdio.h>
#include <stdlib.h>

int NH;

void    guardar_hermanos(int *ph);
void    mostrar_hermanos(int *ph);
void    mayor_cant_hermanos(int *ph);

int main()
{
    int *num_hermanos;
    printf("Cuantas personas deseas capturar?\n" );
    scanf("%i",&NH);
    num_hermanos = malloc(NH*sizeof(int));
    guardar_hermanos(num_hermanos);
    mostrar_hermanos(num_hermanos);
    mayor_cant_hermanos(num_hermanos);
    free(num_hermanos);
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


void    mayor_cant_hermanos(int *ph)
{
    int may = ph[0];
    int ind = 0;
    for(int i=0; i<NH; i++)
    {
        if(ph[i]>may)
        {
            may = ph[i];
            ind = i;
        }
    }
    printf("La persona con mas hermanos es la %i que tiene %i hermanos \n", ind+1, may);
    return;
}