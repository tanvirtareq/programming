#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned n, i, q, x, b,e, m, t1,t2;

    scanf("%llu", &n);

    long long unsigned a[n];

    for(i=0;i<n;i++)
    {
        scanf("%llu", &a[i]);
    }

    scanf("%llu", &q);

    for(i=1;i<=q;i++)
    {
        scanf("%llu", &x);

        if(x<a[0]) printf("X %llu\n", a[0]);

        else if(x>a[n-1]) printf("%llu X\n", a[n-1]);

        if(a[0]<=x&&a[n-1]>=x)
        {



        b=0;
        e=n-1;

        while(b<e)
        {
            m=(b+e)/2;

            if(a[m]==x)
            {
                if(m!=0&&m!=n-1)
                {
                    printf("%llu %llu\n", a[m-1], a[m+1]);

                }

                else if(m==0&&m!=n-1)
                    printf("X %llu\n",  a[m+1]);

                else if(m!=0&&m==n-1)
                    printf("%llu X\n",  a[m-1]);

                else if(m==0&&m==n-1)
                    printf("X X\n");


                    break;



            }

            if(b==m)
            {
                printf("%llu %llu\n", a[b], a[b+1]);
                break;

            }

            else if(x<a[m]) e=m;

            else b=m;


        }

        }



    }

    return 0;
}
