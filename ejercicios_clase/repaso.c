#include <stdio.h>
#include <stdlib.h>

int main()
{
    p3();
    return 0;
}


void p1()
{
    int x=5, y=6, z=1, *p=&x;
    while(*p < 9)
    {
        if(x%2 == 0)
        {
            y *= 2;
            p = &y;
        }
        else
        {
            z -=3;
            p = &z;
        }
        printf("%i \n",x+(*p));
        p = &x;
        (*p)++;
    }
    z++;

    printf("x=%i, y=%i, z=%i \n",x,y,z);

}

void p2()
{
    int x=5, y=6, z=1, *p=&x;
    for(int j=0; j<3; j++)
    {
        if(x%3 == 0)
        {
            y *= 2;
            p = &z;
        }
        else
        {
            z -=3;
            p = &y;
        }
        printf("%i \n",x-(*p));
        x++;
    }
    z++;
    printf("x=%i, y=%i, z=%i \n",x,y,z);
}


void p3()
{
    int x[10]={5,3,8,1,7,8,6,9,7,6}, y=6, z=1, *p=x;
    do
    {
        if(y%3 == 0)
        {
            p += 2;
        }
        else
        {
            p--;
        }
        printf("%i \n",z+(*p));
        z = y+(*p);
        y++;
    }
    while(y<10);
    printf("p=%i, y=%i, z=%i \n",*p,y,z);
}