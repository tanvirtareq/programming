/** given by enam sir
same as matrix multiplication

*/

#include<stdio.h>

int main()
{
    int m, n,r,c, p,q, a[100][100], b[100][100], ans[100][100];
    /** a array is m*n  and b array is p*q */




    while(1){
    scanf("%d%d", &m, &n);

    for(r=0;r<m;r++)
    {
        for(c=0;c<n;c++)
        {
            scanf("%d", &a[r][c]);
        }
    }

    scanf("%d%d",&p,&q);

    for(r=0;r<p;r++)
    {
        for(c=0;c<q;c++)
        {
            scanf("%d", &b[r][c]);
        }
    }

    if(n==p)
    {
        for(r=0;r<m;r++)
        {
            for(c=0;c<q;c++)
            {
                int sum=0;
                for(int temp=0;temp<n;temp++)
                {
                    sum=a[r][temp]*b[temp][c]+sum;

                }
                ans[r][c]=sum;
            }
        }
    }

    for(r=0;r<m;r++)
    {
        for(c=0;c<q;c++)
        {
            printf("\t%d\t", ans[r][c]);
        }
        puts("");
    }

    }

    return 0;
}

