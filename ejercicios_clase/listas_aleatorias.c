#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct perro{
    char raza[30];
    int edad;
    float peso;
    float altura;
};

char lista[][30]={
"Salchicha",
"Bull Dog",
"Chihuahua",
"Pastor Aleman",
"Pastor Ingles",
"Pit Bull",
"Doberman",
"Husky",
"Labrador",
"Esnauser",
"Pug",
"Sharpei",
"Xolo Escuintle",
"Galgo"
};

int main()
{
    struct perro p1;
    int segundos;
    int aux;
    segundos = time(NULL);
    srand(segundos);
    p1.edad = rand() % 16;
    printf("la Edad del perro es  %i \n", p1.edad);

    aux = rand()%4980 + 20;
    p1.peso = (float)aux /100;
    printf("el peso del perro es  %.2f kg \n", p1.peso);


    //2-----16
    aux = rand() % 15 + 2; /// 2---16
    p1.altura = (float) aux / 10; //0.2 ----- 1.6
    printf("la altura  del perro es  %.1f m \n", p1.altura);

    aux = rand() % 14; // depende de los elementos de la lista
    strcpy(p1.raza, lista[aux]);
    printf("la raza  del perro es  %s \n", p1.raza);
    return 0;

}