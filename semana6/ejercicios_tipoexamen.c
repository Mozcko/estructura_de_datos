#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// si el array 


int main(int argc, char **argv){
    int x[] = {5,9,3,8,2};
    int *p = &x[4];
    p -= 2;
    *p *= 3;
    printf("%i", *p);
    return 0;
}