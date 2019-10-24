#include<stdio.h>
#include<iostream>
int main()
{

    int d;
    scanf("%d", &d);

    switch(d)
    {
    case 5:
        puts("5");

        return 1;
    default:
        puts("un");
    case 10:
        puts("10");
    }


    return 0;
}
