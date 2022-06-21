#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct perro{
    char raza[30];
    int edad;
    float peso;
    float altura;
};

char razas[][30] = {
    "salchicha",
    "bulldog",
    "chihuahua",
    "pastor aleman",
    "pastor ingles",
    "pitbull",
    "doberman",
    "husky",
    "labrador",
    "schnauzer",
    "pug",
    "sharpei",
    "xoloescuincle",
    "galgo"
};


int main(){
    struct perro p1;
    int aux;

    srand(time(NULL));

    p1.edad = rand() % 16;
    printf("la edad del perro es %i \n", p1.edad);

    aux = (rand() % 4980) + 20;
    p1.peso = (float)(aux) / 100;
    printf("el peso del perro es %.2f kg \n", p1.peso);

    aux = (rand() % 130) + 30;
    p1.altura = (float)(aux) / 100;
    printf("la altura del perro es %.2f m \n", p1.altura);

    aux = rand() % 14;
    strcpy(p1.raza, razas[aux]);
    printf("la raza del perro es %s \n", p1.raza);
    return 0;
}