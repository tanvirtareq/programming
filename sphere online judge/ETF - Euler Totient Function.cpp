
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll totient(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main()
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", totient(n));
    }

    return 0;
}


