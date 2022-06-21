#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NP  5

struct persona{
  char nombre[30];
  int edad;
  float estatura;
  char genero;

};

void guardar_persona(struct persona *pp);
void mostrar_datos(struct persona pp);
void persona_mas_alta(struct persona *pp);
void persona_mas_joven(struct persona *pp);
void primer_persona_alf(struct persona *pa);
int main()
{

    struct persona per[NP];

    for(int i=0; i<NP; i++)
    {
        guardar_persona(&per[i]);
    }

    for(int i=0; i<NP; i++)
    {
        mostrar_datos(per[i]);
    }
    persona_mas_alta(per);
    persona_mas_joven(per);
    primer_persona_alf(per);
    return 0;
}

void guardar_persona(struct persona *pp)
{
    printf("Ingresa el nombre de la persona \n");
    fflush(stdin);
    gets(pp->nombre);
    printf("ingresa la edad de %s \n", pp->nombre);
    scanf("%i",&pp->edad);
    printf("ingresa la estatura de %s \n", pp->nombre);
    scanf("%f",&pp->estatura);
    printf("ingresa el genero de %s \n", pp->nombre);
    fflush(stdin);
    scanf("%c",&pp->genero);
    return;
}

void mostrar_datos(struct persona pp)
{
    printf("%s tiene %i anios, mide %.2f metros y es del genero %c \n",pp.nombre,pp.edad,pp.estatura,pp.genero);
    return;
}

void   persona_mas_alta(struct persona *pp)
{

    float may = pp[0].estatura;
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].estatura>may)
        {
            may = pp[i].estatura;
            ind = i;
        }
    }
    printf("La persona  mas alta es  %s que mide %.2f metros \n", pp[ind].nombre, may);
    return;
}


void   persona_mas_joven(struct persona *pp)
{

    int menor = pp[0].edad;
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].edad < menor)
        {
            menor = pp[i].edad;
            ind = i;
        }
    }
    printf("La persona  mas joven es  %s que tiene %i anios \n", pp[ind].nombre, menor);
    return;
}



void   primer_persona_alf(struct persona *pa)
{

    char  menor[30];
    strcpy(menor ,pa[0].nombre);
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if( strcmp(pa[i].nombre,menor) < 0 )
        {
            strcpy(menor, pa[i].nombre);
            ind = i;
        }
    }
    printf("En una lista ordenada alfabeticamente la primer persona  es %s \n", menor);
    return;
}