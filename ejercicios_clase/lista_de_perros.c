#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct perro{
    char raza[30];
    int edad;
    float peso;
    float altura;
};

void agregar(struct perro *pdog, int cant);
void mostrar(struct perro *pdog, int cant);
void modificar(struct perro *pdog, int cant);


char lista[][30]={
"Salchicha",
"Bull Dog",
"Chihuahua",
"Pastor Aleman",
"Pastor Ingles",
"Pit Bull",
"Doberman",
"Husky",
"Labrador",
"Esnauser",
"Pug",
"Sharpei",
"Xolo Escuintle",
"Galgo"
};

int main()
{
    int segundos;
    segundos = time(NULL);
    srand(segundos);
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
    printf("la Edad del perro es  %i \n", pdog[cant].edad);

    aux = rand()%4980 + 20;
    pdog[cant].peso = (float)aux /100;
    printf("el peso del perro es  %.2f kg \n", pdog[cant].peso);


    //2-----16
    aux = rand() % 15 + 2; /// 2---16
    pdog[cant].altura = (float) aux / 10; //0.2 ----- 1.6
    printf("la altura  del perro es  %.1f m \n", pdog[cant].altura);

    aux = rand() % 14; // depende de los elementos de la lista
    strcpy(pdog[cant].raza, lista[aux]);
    printf("la raza  del perro es  %s \n", pdog[cant].raza);
    return;
}

void mostrar(struct perro *pdog, int cant)
{
    for(int i=0; i<cant; i++){
        printf("El perro %s tiene %i anios, pesa %.2f kg y mide %.1f m \n",pdog[i].raza, pdog[i].edad, pdog[i].peso, pdog[i].altura);
    }

    return;
}



void modificar(struct perro *pdog, int cant)
{
    int pos;
    do
    {
        printf("Que perro de la lista quieres modificar? \n");
        scanf("%i",&pos);
        if(pos>cant || pos < 1)
        {
            printf("No existe esa posicion \n");
            Sleep(1000);
            system("cls");
        }
    }
    while(pos>cant || pos <1);
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