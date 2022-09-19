#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x, y, z, *p;
    x = 0; 
    y = 3; 
    z = 10;
    p = &x;
    
    do{ 
        if(y%3 == 0)
        {
            z-=2; 
            *p+=3;
        } 
        else 
        {
            *p+=2;
        }
        printf("%i\n",(*p)+y-z); 
        y++; 
        }while(*p<=10); 
        *p-=(x%z); 
        //printf("%i\n",x); 
}