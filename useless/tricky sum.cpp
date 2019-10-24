#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int i, j,t, k;

    long long int n;
    long long int sum;

    double li, lj, lk;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);
         long long int sumn=n*(n+1)/2;


        long long int sumneg=0;

        for(i=1;i<=n;)
        {
            sumneg=sumneg+i;

            i=i*2;


        }

        sum=sumn-2*sumneg;

        printf("%lld\n", sum);

    }

    return 0;
}
