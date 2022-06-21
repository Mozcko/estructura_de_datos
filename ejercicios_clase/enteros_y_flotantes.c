#include <stdio.h>
#include <stdlib.h>
void guardar_datos(int *pi, float *pf);
void mostrar_datos(int di, float df);

int main()
{
    float estatura;
    int num_mascotas;
    guardar_datos(&num_mascotas,&estatura);
    mostrar_datos(num_mascotas,estatura);
    printf("Hello world!\n");
    return 0;
}

void guardar_datos(int *pi, float *pf)
{
     printf("Ingresa la cantidad de mascotas\n");
     scanf("%i",pi);
     printf("Ingresa la estatura\n");
     scanf("%f",pf);
     return;
}

void mostrar_datos(int di, float df)
{

    printf("La persona mide %.2f y tiene %i mascotas \n",df,di);
    return;
}