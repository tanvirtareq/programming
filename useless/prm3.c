#include<stdio.h>

int is_prm(int x)
{
    int i=2;

    for(i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
            break;
        }



    }
    return 1;

}
main()
{
    int x ;
    int i=1;


    x=3;

    for(x=3;;x++)
    {

        if(1==is_prm(x))
        {

            printf("\n%d", x);
        }
    }

}
