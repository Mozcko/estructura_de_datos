#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct juego{
    char nombre[30];
    float horasHistoria;
    int personajes;
};

char nombresJuegos[][30] = {
    "Gurion",
    "Anbor",
    "Zuylon",
    "Relka",
    "Baragu",
    "Kezo",
    "Xarod",
    "Glorhea",
    "Dexamyre Adriggon",
    "Staux Papher",
    "Lazlyre Elhora",
    "Joquar Riecto",
    "Clux Jocen",
    "Xernes Kaljeon",
};

void menu();
void agregar(struct juego *pgame, int cant);
void mostrar(struct juego *pgame, int cant);
void modificar(struct juego *pgame, int cant);

int main(int argc, char **argv){
    srand(time(NULL));
    menu();
    return 0;
}


void menu(){
    int op;
    struct juego game[14];
    int n = 0;
    do{
        system("cls");
        printf("Selecciona la opcion deseada\n"
               "\t1\tAgregar un juego\n"
               "\t2\tMostrar lista\n"
               "\t3\tBorrar ultimo juego de la lista\n"
               "\t4\tModificar un juego de la lista\n"
               "\t5\tSalir \n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            agregar(game, n);
            n++;
            break;
        case 2:
            mostrar(game, n);
            break;
        case 3:
            n--;
            break;
        case 4:
            modificar(game, n);
            break;
        case 5:
            printf("Adios \n");
            break;
        default:
            printf("Opcion incorrecta \n");
        }
        system("pause");
    }while(op != 5);
    return;
}

void agregar(struct juego *pgame, int cant){
    int aux;
    pgame[cant].personajes = rand() % 201;
    aux = (rand() % 180) + 21;
    pgame[cant].horasHistoria = (float)aux / 10;
    aux = rand() % 14;
    strcpy(pgame[cant].nombre, nombresJuegos[aux]);

    printf("el nombre del juego es: %s \n",pgame[cant].nombre);
    printf("tiene %.2f horas de historia \n", pgame[cant].horasHistoria);
    printf("hay %i personajes secundarios \n", pgame[cant].personajes);

    return;
}

void mostrar (struct juego *pgame, int cant){
    for(int i=0; i<cant; i++){
        printf("%i      %s tiene %.2f horas de historia y %i personajes \n", i + 1, pgame[i].nombre, pgame[i].horasHistoria, pgame[i].personajes);
    }
    return; 
}

void modificar (struct juego *pgame, int cant){
    int pos;
    do{
        printf("elige el juego que quieres modificar \n");
        for(int i=0; i<cant; i++){
            printf("\t%d \t %s \n", i + 1, pgame[i].nombre);
        }
        scanf("%i", &pos);
        if(pos> cant || pos < 1){
            printf("No existe esa posicion\n");
            Sleep(1000);
            system("cls");
        }

    }while (pos > cant || pos < 1);
    printf("escribe el nombre del juego\n");
    fflush(stdin);
    gets(pgame[pos - 1].nombre);
    printf("escribe las horas de historia del juego %s\n", pgame[pos - 1]);
    scanf("%f", &pgame[pos - 1].horasHistoria);
    printf("escribe el numero de personajes del juego %s\n", pgame[pos - 1]);
    scanf("%i", &pgame[pos - 1].personajes);
    return;
}