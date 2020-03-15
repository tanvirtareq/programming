#include<stdio.h>

int main()
{
    int a[]={1, 3,4,6,7,9,13,24,35};

    int k=12, t, i, j;

    for(i=0;i<9;i++)
    {
        if(a[i]>=k)
        {
            t=a[i];

            a[i]=k;

            k=t;


        }

    }

    for(i=0;i<9;i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}
