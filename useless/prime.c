#include<stdio.h>

int is_prm(int x, int n[100])
{
    int j;

    for(j=1;j<x;j++)
    {
        if(x%n[j]==0)
        {
            return 0;
            break;
        }
        return 1;
    }


}
main()
{
    int n[100], i;
    n[1]=2;
    n[2]=3;
    n[3]=4;
    for(i=3;i<=100;i++)
    {

        if(1==is_prm(n[i], n))
        {
            printf("\n%d" ,n[i]);


        }

    }
}
