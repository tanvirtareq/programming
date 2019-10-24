#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int ara1[n][m],ara2[n][m],ara3[n][m];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            scanf("%d",&ara1[i][j]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            scanf("%d",&ara2[i][j]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            ara3[i][j]=ara1[i][j]-ara2[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d", ara3[i][j]);
            if(j!=m-1) printf(" ");
        }
        puts("");
    }



    return 0;

}
