#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int array[10001],i;

    srand(time(NULL));

    for(i=1; i<=1000; i++)
    {
        array[i]=(rand()%100);
    }

    for(i=1; i<=1000; i++)
    {
        printf("%d ", array[i]);
    }

}
