#include<stdio.h>
#include<stdlib.h>

int main(int argc, char){
    int librosNum, librosMax, *punteroInt;
    float duracionPelicula, duracionCorto, *punteroFloat;
    char nombreSaga, nombrePelicula, *punteroChar;

    printf("cuantos libros has leido? ");
    punteroInt = &librosNum;
    scanf("%i", punteroInt);
    punteroInt = &librosMax;
    *punteroInt = 550;
    punteroFloat = &duracionPelicula;
    printf("cuanto tiempo dura (en hrs) tu pelicula favorita? ");
    scanf("%f", punteroFloat);
    punteroFloat = &duracionCorto;
    *punteroFloat = 15.5;
    punteroChar = &nombrePelicula;
    *punteroChar = 'S';
    punteroChar = &nombreSaga;
    printf("cual es l aprimera letra del nombre de tu saga favorita?");
    fflush(stdin);
    scanf("%c", punteroChar);

    printf("has leido %i libros, tu libro favorito tiene %i paginas\n"
           "tu pelicula favorita dura %0.2f horas, tu cortometraje favorito dura %0.2f minutos\n"
           "tu pelicula favorita empieza con la letra %c y tu saga favorita empieza por la letra %c\n", librosNum, *punteroInt, duracionPelicula, *punteroFloat, nombrePelicula, *punteroChar
           );   
    return 0;
}