
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

#define MX 10000000

int lp[MX + 10];
int phi[MX + 10];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= MX; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MX; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    for(ll i=a;i<=b;i++)
    {
        printf("%lld\n", phi[i]);
    }

    return 0;
}



