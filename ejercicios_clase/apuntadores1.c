#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3; // Se crean 3 espacios para guardar enteros
    float val1, val2, val3;//se crean 3 espacios para guardar num reales.
    char let1, let2, let3;// se crean 3 espacios para guardar caracteres
    int *p1;
    float *apuntador;
    char *ap1, *ap2;
    p1 = &num1; //p1 apunta a num1
    p1 = &num3; //p1 apunta a num3
    *p1 = 87; // guarda en  num3 el 87
    p1 = &num2; // p1 apunta a num2
    *p1 = 5; //guarda el 5 en num2;
    p1= &num1; //p1 apunta a num1
    *p1 = num3; // se guarda en num1 lo que hay en num3
    apuntador = &val2;
    printf("Ingresa la estatura de una persona");
    scanf("%f",apuntador);
    printf("la estatura es %f\n",*apuntador);
    printf("num1= %i, num2 =%i, num3=%i\n",num1,num2,num3);
    apuntador= &val3; //apuntador apunta a val3
    *apuntador = val2 + 1;
    printf("la estatura es %f\n",*apuntador);
    ap1 = &let2;
    *ap1 = '@';
    printf("let2 =  %c\n",let2);
    printf("let2 =  %c\n",*ap1);
    ap2 = ap1; //
    printf("let2 =  %c\n",*ap2);
    return 0;
}