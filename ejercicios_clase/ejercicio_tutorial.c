#include<stdio.h>
//#include<conio.h>

#define TAMANO 5

void cargar(float *p)
{
    int f;
    for(f=0;f<TAMANO;f++)
    {
        printf("Ingrese elemento:");
        scanf("%f",p+f);
    }
}

void imprimir(float *p)
{
    int f;
    for(f=0;f<TAMANO;f++)
    {
        printf("%0.2f ",p[f]);
    }
}


int main()
{
    float vec[TAMANO];
    cargar(vec);
    imprimir(vec);
    getch();
    return 0;
}