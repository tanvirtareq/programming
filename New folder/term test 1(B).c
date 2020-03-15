#include<stdio.h>
#include<math.h>
int main()
{

    int n, m=10e2, i=6,j;
    double r;
    char c[]="i=%d, j=%d, n=%d, m=%d\n%s";

    scanf("%d %d %lf", &n, &m, &r);

    for(j=491;i>=-5;n=(i%(m+70))%(n*5)-7)
    {
        for(;;i=(j%97)%(m*51))
        {
            printf(c,m,i,j,n,c);
            j=ceil(j+r*314);
            if(j>4.65e3) break;

        }
        printf("%-4d#%02d#\n",i,j,n,m);
        if(i+j+n+m>7E3) break;
    }
    return 0;

}
