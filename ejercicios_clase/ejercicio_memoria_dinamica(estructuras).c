#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX;

struct perro
{
    char raza[30];
    int edad;
    float peso;
    float altura;
};

void agregar(struct perro *pdog);
void mostrar(struct perro *pdog);
void modificar(struct perro *pdog);
void pesado(struct perro *pdog);

char lista[][30]=
{
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
    struct perro *dog;
    int n = 0; // cantidad de perros en la lista;
    printf("Numero de  perros en la lista\n");
    scanf("%i",&MAX);
    dog = malloc(MAX*sizeof(struct perro));
    agregar(dog);
    do
    {

        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tLlenar  la lista de perros\n"
               "\t2\tMostrar Lista\n"
               "\t3\tMostrar el perro mas pesado\n"
               "\t4\tModificar elemento de la lista\n"
               "\t5\tRedefinir el tamnio de la lista\n"
               "\t6\tSalir \n"
              );
        scanf("%i",&op);
        switch(op)
        {
        case 1:

            agregar(dog);
            break;
        case 2:
            mostrar(dog);
            break;
        case 3:
            pesado(dog);
            break;
        case 4:
            modificar(dog);
            break;
        case 5:
            free(dog);
            printf("Numero de  perros en la lista\n");
            scanf("%i",&MAX);
            dog = malloc(MAX*sizeof(struct perro));
            agregar(dog);
            break;
        case 6:
            printf("Adios \n");
            break;
        default:
            printf("Opcion Incorrecta \n");

        }
        system("pause");
    }
    while(op != 6);
    free(dog);
    return;
}

void agregar(struct perro *pdog)
{

    int j, aux;
    for(j=0 ; j<MAX; j++)
    {
        pdog[j].edad = rand() % 16;
        printf("la Edad del perro es  %i \n", pdog[j].edad);

        aux = rand()%4980 + 20;
        pdog[j].peso = (float)aux /100;
        printf("el peso del perro es  %.2f kg \n", pdog[j].peso);


        //2-----16
        aux = rand() % 15 + 2; /// 2---16
        pdog[j].altura = (float) aux / 10; //0.2 ----- 1.6
        printf("la altura  del perro es  %.1f m \n", pdog[j].altura);

        aux = rand() % 14; // depende de los elementos de la lista
        strcpy(pdog[j].raza, lista[aux]);
        printf("la raza  del perro es  %s \n", pdog[j].raza);
    }

    return;
}

void mostrar(struct perro *pdog)
{
    for(int i=0; i<MAX; i++)
    {
        printf("El perro %s tiene %i anios, pesa %.2f kg y mide %.1f m \n",pdog[i].raza, pdog[i].edad, pdog[i].peso, pdog[i].altura);
    }

    return;
}



void modificar(struct perro *pdog)
{
    int pos;
    do
    {
        printf("Que perro de la lista quieres modificar? \n");
        scanf("%i",&pos);
        if(pos>MAX || pos < 1)
        {
            printf("No existe esa posicion \n");
            Sleep(1000);
            system("cls");
        }
    }
    while(pos>MAX || pos <1);
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

void pesado(struct perro *pdog)
{
    float mayor = pdog[0].peso;
    int indice = 0;
    for(int i=0; i<MAX; i++)
    {
        if(pdog[i].peso > mayor)
        {
            mayor = pdog[i].peso;
            indice = i;
        }
    }
    printf("Los datos del perro mas pesado son:\n");
    printf("El perro %s tiene %i anios, pesa %.2f kg y mide %.1f m \n",pdog[indice].raza, pdog[indice].edad, pdog[indice].peso, pdog[indice].altura);
}