#include <stdio.h>
#include <stdlib.h>

void saludar(); // Declaracion de la funcion
float ejemplo();
float suma(float num1, float num2);

int main()
{
    float valor1,valor2;
    printf("Escribe el primer numero  \n");
    scanf("%f",&valor1);
    printf("Escribe el segundo numero  \n");
    scanf("%f",&valor2);
    printf("El resultado de la suma es %f \n", suma(valor1,valor2));
    return 0;
}


void saludar()
{
    printf("Buenas Noches\n");
    return;
}

float ejemplo()
{
  return 1.65;
}


float suma(float num1, float num2)
{
    return num1+num2;
}