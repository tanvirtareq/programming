#include<bits/stdc++.h>
#define ll long long
#define MX 1001000

using namespace std;

ll p[MX+10], g[MX+10];

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

void gcdx()
{
    for(ll i=2;i<=MX;i++) g[i]=phi[i];

    for(ll i=2;i<=MX;i++)
    {

            for(ll j=i+i;j<=MX;j+=i)
            {
                g[j]+=j*phi[i]/i;
            }

    }

    for(ll i=2;i<=MX;i++) g[i]+=g[i-1];
}

int main()
{
    calc_sieve();

    gcdx();

    ll n;
    while(cin>>n)
    {
        if(n==0) break;


        cout<<g[n]<<endl;
    }

    return 0;
}
