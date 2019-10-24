#include<stdio.h>
#include<math.h>

typedef long long int ll;

double ar[1000000];



double lgfact(ll n)
{
    if(ar[n]!=0) return ar[n];
    else if(n<=1)
    {
        return 0;
    }
    else
    {
        double y=log10(n)+lgfact(n-1);
//        ll x=(ll)y;
        ar[n]=y;
//        printf("%lld\n", x);
        return y;
    }
}

int main()
{
    ar[1]=0;

    ll t;
    scanf("%lld", &t);
    while(t--)
    {
       ll n;
       scanf("%lld", &n);
       double y;
       y=n*lgfact(n)+1;
       ll fn=(ll)y;

//       ll ans=n*log10(fn)+1;
       printf("%lld\n", fn);
    }

    return 0;
}

