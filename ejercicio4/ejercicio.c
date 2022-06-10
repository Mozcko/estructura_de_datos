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
void persona_mas_baja(struct persona *pp);
void primer_persona_alf(struct persona *pp);
void ultima_persona_alf(struct persona *pp);
void persona_under_20(struct persona *pp);
void persona_under_160(struct persona *pp);
void persona_mas_vieja(struct persona *pp);
void existe_luis(struct persona *pp);

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
    persona_mas_vieja(per);
    primer_persona_alf(per);
    persona_mas_baja(per);
    ultima_persona_alf(per);
    persona_under_20(per);
    persona_under_160(per);
    existe_luis(per);
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

void persona_mas_baja(struct persona *pp){
    float menor = pp[0].estatura;
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].estatura<menor)
        {
            menor = pp[i].estatura;
            ind = i;
        }
    }
    printf("La persona  mas baja es  %s que mide %.2f metros \n", pp[ind].nombre, menor);
    return;
}

void   persona_under_160(struct persona *pp)
{
    int menores = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].estatura < 1.60 )
        {
            menores ++;
        }
    }
    printf("La cantidad de personas que miden menos de 1.60 son %i \n", menores);
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

void   persona_mas_vieja(struct persona *pp)
{

    int mayor = pp[0].edad;
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].edad > mayor)
        {
            mayor = pp[i].edad;
            ind = i;
        }
    }
    printf("La persona  mas vieja es  %s que tiene %i anios \n", pp[ind].nombre, mayor);
    return;
}

void   persona_under_20(struct persona *pp)
{

    int menor20 = 0;
    for(int i=0; i<NP; i++)
    {
        if(pp[i].edad < 20)
        {
            menor20++;
        }
    }
    printf("La cantidad de personas menores a 20 anios son %i \n", menor20);
    return;
}

void   primer_persona_alf(struct persona *pp)
{

    char  menor[30];
    strcpy(menor ,pp[0].nombre);
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if( strcmp(pp[i].nombre,menor) < 0 )
        {
            strcpy(menor, pp[i].nombre);
            ind = i;
        }
    }
    printf("En una lista ordenada alfabeticamente la primer persona  es %s \n", menor);
    return;
}

void   ultima_persona_alf(struct persona *pp)
{
    char  mayor[30];
    strcpy(mayor ,pp[0].nombre);
    int ind = 0;
    for(int i=0; i<NP; i++)
    {
        if( strcmp(pp[i].nombre,mayor) > 0 )
        {
            strcpy(mayor, pp[i].nombre);
            ind = i;
        }
    }
    printf("En una lista ordenada alfabeticamente la ultima persona  es %s \n", mayor);
    return;
}

void   existe_luis(struct persona *pp)
{   
    for(int i=0; i<NP; i++)
    {
        if( strcmp(pp[i].nombre,"luis") > 0 )
        {
            printf("Dentro de la lista de las personas existe una persona llamada luis \n");
        }
    }
    return;
}