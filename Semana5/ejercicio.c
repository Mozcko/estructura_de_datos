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

void menu();
void agregar(struct perro *pdog, int cant);
void mostrar(struct perro *pdog, int cant);
void modificar(struct perro *pdog, int cant);

int main()
{
    srand(time(NULL));
    menu();
    
    return 0;
}


void menu()
{
    int op;
    struct perro dog[14];
    int n = 0; // cantidad de perros en la lista;
    do
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tAgregar perro a la lista\n"
               "\t2\tMostrar Lista\n"
               "\t3\tBorrar ultimo perro de la lista\n"
               "\t4\tModificar elemento de la lista\n"
               "\t5\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            agregar(dog, n);
            n++;
            break;
        case 2:
            mostrar(dog, n);
            break;
        case 3:
            n--;
            break;
        case 4:
            modificar(dog, n);
            break;
        case 5:
            printf("Adios \n");
            break;
        default:
            printf("Opcion Incorrecta \n");

        }
        system("pause");
    }
    while(op != 5);
    return;
}

void agregar(struct perro *pdog, int cant)
{
    int aux;

    pdog[cant].edad = rand() % 16;
    printf("la edad del perro es %i \n", pdog[cant].edad);

    aux = (rand() % 4980) + 20;
    pdog[cant].peso = (float)(aux) / 100;
    printf("el peso del perro es %.2f kg \n", pdog[cant].peso);

    aux = (rand() % 15) + 2;
    pdog[cant].altura = (float)(aux) / 100;
    printf("la altura del perro es %.2f m \n", pdog[cant].altura);

    aux = rand() % 14;
    strcpy(pdog[cant].raza, razas[aux]);
    printf("la raza del perro es %s \n", pdog[cant].raza);
    return;
}

void mostrar(struct perro *pdog, int cant)
{
    for (int i = 0; i < cant; i++){
        printf("El Perro %s tiene %i anios, pesa %.2f kg y mide %.2f m \n", pdog[i].raza, pdog[i].edad, pdog[i].peso, pdog[i].altura);
    }
    return;
}

void modificar(struct perro *pdog, int cant)
{
    int pos;
    do {
        printf("ingrese el perro de la lista que quiere modificar \n");
        scanf("%i", &pos);
        if (pos > cant || pos < 1){
            printf("no existe esa posicion de la lista \n");
            system("cls");
        }
    }while ((pos > cant));
    printf("Escribe la raza del perro \n");
    fflush(stdin);
    gets(pdog[pos-1].raza);
    printf("Escribe la edad del perro %s \n",pdog[pos-1]);
    scanf("%i",&pdog[pos-1].edad);
    printf("Escribe el peso del perro %s \n",pdog[pos-1]);
    scanf("%f",&pdog[pos-1].peso);
    printf("Escribe la altura del perro %s \n",pdog[pos-1]);
    scanf("%f",&pdog[pos-1].altura);

    return;
}