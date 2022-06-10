#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ejercicio[15]="Tutorial", inicial='k', *pp;
    int valores[15]={9,3,6,7,3,6,5,6,7,77,11,44,66,77,88};
    int *pi;
    pi = &valores[3];
    pi -=2;
    pp = ejercicio;
    printf("La letra es %c \n", inicial);
    printf("La letra es %c \n", *(pp + 3));
    pp++;
    printf("La letra es %c \n", *pp);
    printf("La palabra es %s \n",pp);
    pp=&inicial;
    printf("La letra es %c \n", *pp);
    *pp = 'y';
    printf("La letra es %c \n", *pp);
    printf("----------------------------------------\n");
    printf("%i\n",pi);
    printf("----------------------------------------\n");
    printf("------------------direcciones-----------\n");
    for(int i=0; i<15;i++)
    printf("%i\n",&valores[i]);
     printf("----------------contenidos-----------\n");
    for(int i=0; i<15;i++)
    printf("%i\n",valores[i]);

     printf("----------------------------------------\n");
    printf("%i \n",*pi);
    return 0;

}