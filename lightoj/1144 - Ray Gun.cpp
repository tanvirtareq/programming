#include<bits/stdc++.h>
#define ll long long
#define MX 1100000
using namespace std;

int lp[MX + 10];
int phi[MX + 10];
vector<int> prime;
void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= MX; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            prime.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= MX; ++j)
            lp[i * prime[j]] = prime[j];
    }
}


int main()
{
    int t;
    cin>>t;
    calc_sieve();
    for(int in=1; in<=t; in++)
    {
        ll n,m;
        cin>>m>>n;
        if(m==0 || n==0)
        {
            cout<<"Case "<<in<<": "<<1<<endl;
            continue;
        }
        if(m<n)
            swap(m, n);

        vector<ll> v;
        for(ll i=0; prime[i]<=n; i++)
        {
            v.push_back(prime[i]);
        }

        int mx=v.size();
        mx=(1<<mx)-1;
//        cout<<mx<<endl;

        ll ans=0;

        for(int s=1; s<=mx; s++)
        {
            ll x=1;
            ll ct=0;
            for(int i=0; i<v.size(); i++)
            {
                if(s&(1<<i))
                {
                    ct++;
                    x*=v[i];
//                    cout<<ct<<" ah"<<x<<endl;
                }
            }
            if(ct%2)
                ans+=(n/x)*(m/x);
            else
                ans-=(n/x)*(m/x);

        }
        cout<<"Case "<<in<<": "<<n*m-ans+2<<endl;

    }
    return 0;
}
