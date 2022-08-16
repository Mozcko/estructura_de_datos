#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){
    int a[5]={10,20,30,40,50};
    int *c=&a[2];
    *c+=3;

    printf("%i",*c);
}

