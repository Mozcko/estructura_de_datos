#include<stdio.h>
#include<stdlib.h>


float multiplicar(int, int);
float dividir(int, int);

int main(){
    int x;
    int y;
    char respuesta;

    printf("bienvenido a la calculadora\n");
    printf("escoja si quiere multiplicar o dividir (m)/(d) ");
    scanf("%c", &respuesta);

    if (respuesta == 'm'){
        int res;
        printf("introduzca el primer numero a multiplicar ");
        scanf("%d", &x);
        printf("introduzca el segundo numero a multiplicar ");
        scanf("%d", &y);

        res = multiplicar(x,y);
        printf("el resultado de la multiplicacion es %d \n", res);
    }
    else if (respuesta == 'd'){
        float res;
        printf("introduzca el primer numero a dividir ");
        scanf("%d", &x);
        printf("introduzca el segundo numero a dividir ");
        scanf("%d", &y);

        res = dividir(x, y);
        printf("el resultado de la division es %f \n", res);
    }
    return 0;
}


float multiplicar(int x, int y){
    int res = x * y;
    return res;
}

float dividir(int x, int y){
    float res = x / y;
    return res;
}