#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n, *px;

    printf("Cuantas edades deseas capturar?\n" );
    scanf("%i",&n);
    px = malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
    {
        printf("escribe la edad %i\n",i+1);
        scanf("%i",px+i);
    }
    for(i=0; i<n; i++)
    {
        printf("La edad %i es %i \n",i+1,*(px+i));
    }
    free(px);
    return 0;
}