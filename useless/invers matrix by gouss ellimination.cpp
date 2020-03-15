#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, r, c, k;
    scanf("%d", &n);  /// n is row and collumn of matrix

    double a[n+1][n+1], b[n+1][n+1], temp1, temp2;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%lf", &a[i][j]);


            if(i==j) b[i][j]=1;

            else b[i][j]=0;

//            printf("a%d%d=%lf\tb%d%d=%lf\n", i, j, a[i][j], i, j, b[i][j]);
        }

        /// b is an identity  matrix

        /// have make a to an identity matrix



    }

    for(i=1;i<=n;i++)
    {
        if(a[i][i]==0)///if a[i][i] is 0 then we can't divide by a[i][i] ..we have to search a row which has an non zero element in this column
        {
            for(j=i+1;j<=n;j++)
            {
                if(a[j][i]!=0)
                {
                    for(c=1;c<=n;c++)
                    {
                        temp1=a[i][c];
                        a[i][c]=a[j][c];
                        a[j][c]=temp1;

                        temp1=b[i][c];
                        b[i][c]=b[j][c];
                        b[j][c]=temp1;

                    }/// inter change row
                }
            }

        }

        temp1=a[i][i];///for dividing all the elements of this(i th ) row

        printf("\ntemp=%lf\n", temp1);

        for(j=1;j<=n;j++)
        {

            a[i][j]=a[i][j]/temp1;

            b[i][j]=b[i][j]/temp1;

            printf("a%d%d=%lf\tb%d%d=%lf\n", i, j, a[i][j], i, j, b[i][j]);


        }
        puts("\n");

        for(r=1;r<=n;r++)///make all the elements of i th column except aii to zero
        {
            if(i==r) continue;///a[i][i] shouldn't be zero

            temp1=a[r][i];///make r i element zero

            for(c=1;c<=n;c++)///for row operation
            {
                a[r][c]=a[r][c]-temp1*a[i][c];

                b[r][c]=b[r][c]-temp1*b[i][c];

                   printf("{a%d%d=%lf\tb%d%d=%lf}\n", r, c, a[r][c], r, c, b[r][c]);

            }
        }

        puts("\n");

    }

    puts("\n\nfinnaly\n");


    for(r=1;r<=n;r++)
    {
        for(c=1;c<=n;c++)
        {

            printf("%lf   ", b[r][c]);

        }

        printf("\n");

    }

    return 0;
}

/**
3
3 0 2
2 0 -2
0 1 1
*/
