#include<stdio.h>

int const size=100;
int ara[100];
int print_f()
{
    int i, j;

    for(i=2;i<size;i++)
    {
        ara[i]=1;
        printf("%4d", ara[i]);
    }

    printf("\n\n\n");

    for(i=2;i<size;i++)
    {
        printf("____");
    }
}


main()
{
    print_f();
}





