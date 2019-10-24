#include<stdio.h>
main()
{
    int n[100], i, j, p[100];

    n[2]=p[2]=2;

    n[3]=p[3]=3;

    i=3;
    j=2;

    p[4]=0;

    n[i]=4;
    while(i<100)
    {
        if(j>3)
        {
            p[j]=0;
        }
        if(n[i]%p[j]==0)
        {
            n[i]=n[i]+1;
        }

        else
        {
            j=j+1;

            if(p[j]==0)
            {
                p[j]=n[i];
                printf("\n%d", n[i]);

                i=i+1;
            }

        }
    }

}
