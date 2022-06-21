#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NP  3

struct persona{
  char nombre[30];
  int edad;
  float estatura;
  char genero;

};

void guardar_persona(struct persona *pp);
void mostrar_datos(struct persona pp);

int main()
{
    struct persona p1;
    struct persona per[NP];
    strcpy(p1.nombre, "Juan Perez");
    p1.edad=58;
    p1.estatura=1.76;
    p1.genero = 'M';
    printf("%s tiene %i anios, mide %.2f metros y es del genero %c \n",p1.nombre,p1.edad,p1.estatura,p1.genero);
    guardar_persona(&p1);
    mostrar_datos(p1);

    for(int i=0; i<NP; i++)
    {
        guardar_persona(&per[i]);
    }

    for(int i=0; i<NP; i++)
    {
        mostrar_datos(per[i]);
    }
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