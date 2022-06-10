#include<stdio.h>
#include<stdlib.h>

int main(){
    int mayor, menor, igual;
    float alturas[5];
    float suma, promedio;

    for (int i = 0; i < 5; i++){
        printf("ingrese la altura de la persona %d: ", i + 1);
        scanf("%f", &alturas[i]);
    }
    suma = 0;
    for (int i = 0; i < 5; i++) {
        suma = suma + alturas[i];
    }
    promedio = suma/5;
    printf("el promedio de las alturas es de %f \n", promedio);
    mayor = 0;
    menor = 0;
    igual = 0;
    for (int i = 0; i < 5; i++) {
        if (alturas[i] > promedio) {
            mayor++;
        }
        else if (alturas[i] < promedio){
            menor++;
        }else if (alturas[i] == promedio){
            igual++;
        }
    }
    printf("en el grupo hay %i personas mayores al promedio, %i menores al promedio y %i que son iguales al promedio\n", mayor, menor, igual);
    return 0;
}