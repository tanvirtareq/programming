#include<bits/stdc++.h>
#define ll long long
#define MX 1100000
using namespace std;

<<<<<<< HEAD
ll lp[MX + 10];
ll phi[MX + 10];
vector<ll> prime;
=======
int lp[MX + 10];
int phi[MX + 10];
vector<int> prime;
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738
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
<<<<<<< HEAD
    ll t;
//    cin>>t;
    scanf("%lld", &t);
    calc_sieve();
    for(ll in=1; in<=t; in++)
    {
        ll n,m;
//        cin>>m>>n;
        scanf("%lld%lld", &m, &n);
=======
    int t;
    cin>>t;
    calc_sieve();
    for(int in=1; in<=t; in++)
    {
        ll n,m;
        cin>>m>>n;
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738
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

<<<<<<< HEAD
        ll mx=v.size();
        mx=(1LL<<mx)-1;
=======
        int mx=v.size();
        mx=(1<<mx)-1;
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738
//        cout<<mx<<endl;

        ll ans=0;

<<<<<<< HEAD
        for(ll s=1; s<=mx; s++)
        {
            ll x=1;
            ll ct=0;
            for(ll i=0; i<v.size(); i++)
            {
                if(s&(1LL<<i))
=======
        for(int s=1; s<=mx; s++)
        {
            ll x=1;
            ll ct=0;
            for(int i=0; i<v.size(); i++)
            {
                if(s&(1<<i))
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738
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
<<<<<<< HEAD
//        cout<<"Case "<<in<<": "<<n*m-ans+2<<endl;
        printf("Case %lld: %lld\n", in, n*m-ans+2);
=======
        cout<<"Case "<<in<<": "<<n*m-ans+2<<endl;
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738

    }
    return 0;
}
<<<<<<< HEAD

=======
>>>>>>> bc49ef00d5084365b08596a1210048f5cf9fc738
