#include <stdio.h>
#include <stdlib.h>

int rect(int, int );

int main(){
    int l1, l2, l3, l4, rect1, rect2;

    printf("introduzca el valor del lado 1 del rectangulo 1 ");
    scanf("%d", &l1);
    printf("introduzca el valor del lado 2 del rectangulo 1 ");
    scanf("%d", &l2);
    printf("introduzca el valor del lado 1 del rectangulo 2 ");
    scanf("%d", &l3);
    printf("introduzca el valor del lado 2 del rectangulo 2 ");
    scanf("%d", &l4);

    rect1 = rect(l1, l2);
    rect2 = rect(l3, l4);

    printf("la superficie del rectangulo 1 es %d\n", rect1);
    printf("la superficie del rectangulo 2 es %d\n", rect2);

    if (rect1 > rect2){
        printf("el rectangulo con mayor superficie es el rectangulo 1\n");
    } else if (rect1 < rect2){
        printf("el rectangulo con mayorsuperficie es el rectangulo 2\n");
    }

    return 0;
}

int rect(int x, int y){
    int res = x*y;
    return res;
}