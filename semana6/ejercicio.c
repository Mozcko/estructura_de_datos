#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(){

    int i, n, *px;
    printf("cuantas edades deseas capturar?\n");
    scanf("%i",&n);
    px = malloc(sizeof(int)*n);
    for (i = 0; i < n; i++){
        printf("escribe tu edad \n");
        scanf("%i", &px+i);
    }
    for(i = 0; i < n; i++){
        printf("la edad %i es %i \n", i, *px);
    }
    free(px);
    return 0;
}