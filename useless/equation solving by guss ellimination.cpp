#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;

    scanf("%d", &n);///number or variable

    double  a[n+1][n+2];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0)///make exchange with the row which has non zero element in i th column
        {
            for(int r=i+1;r<=n;r++)
            {
                if(a[r][i]!=0)
                {
                    for(int c=1;c<=n+1;c++)
                    {
                        double temp=a[i][c];

                        a[i][c]=a[r][c];

                        a[i][c]=temp;

                    }

                    break;
                }

            }
        }
            double temp=a[i][i];///to make i i th element 1

            for(int j=1;j<=n+1;j++)
            {
                a[i][j]=a[i][j]/temp;

                printf("a%d%d=%lf  \n",i,j, a[i][j]);


            }

            ///make all the elements of i th column 0 except i i th element


            ///by row operation
            for(int r=1;r<=n;r++)
            {
                if(r==i) continue;/// i th row is out of row operation

                double temp=a[r][i];/// target: make  r i th element 0

                for(int c=1;c<=n+1;c++)
                {
                    a[r][c]=a[r][c]-temp*a[i][c];///example: r1=r1-2r2;

                    printf("a%d%d=%lf  \n",r ,c, a[r][c]);

                }
            }
        }



    for(int i=1;i<=n;i++)
    {
        printf("%dth variable=%lf\n",i, a[i][n+1]);


    }

    return 0;
}

/**
3 2 5 7 9 4 1 8 3 5 9 7 0
*/
