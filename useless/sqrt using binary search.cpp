#include<stdio.h>

double mysqrt(int x)
{

    double high=(double) x;

    double dx=(double) x;

    double low=0, mid;

    while((high-low)>0.00000001)
    {
        mid=(high+low)/2;

        printf("mid=%lf\n", mid);

        if(mid*mid==dx) return mid;

        if(mid*mid>dx)
        {

            high=mid;
        }

        else low=mid;


    }


    return mid;
}

int main()
{
    int x;

    while(scanf("%d", &x)!=EOF)
    {
       double sq=mysqrt(x);

        printf("%lf\n", sq);
    }



    return 0;
}
