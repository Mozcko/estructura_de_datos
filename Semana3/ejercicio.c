#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NM  3

struct moto{
  char marca[30];
  char modelo[30];
  float precio;
  int cilindros;
};

void guardar_moto(struct moto *pp);
void mostrar_datos(struct moto pp);

int main()
{
    struct moto per[NM];

    for(int i=0; i<NM; i++)
    {
        guardar_moto(&per[i]);
    }

    for(int i=0; i<NM; i++)
    {
        mostrar_datos(per[i]);
    }
    return 0;
}

void guardar_moto(struct moto *pp)
{
    printf("Ingresa la marca de la moto \n");
    fflush(stdin);
    gets(pp->marca);
    printf("Ingresa el modelo de la marca: %s \n", pp->marca);
    gets( pp->modelo );
    printf("Ingresa el precio de %s \n", pp->modelo);
    scanf("%f",&pp->precio);
    printf("ingresa el numero de cilindros de %s \n", pp->modelo);
    fflush(stdin);
    scanf("%i",&pp->cilindros);
    return;
}

void mostrar_datos(struct moto pp)
{
    printf("la moto modelo %s de la marca %s cuesta %.2f y tiene %i \n",pp.modelo,pp.marca,pp.precio,pp.cilindros);
    return;
}