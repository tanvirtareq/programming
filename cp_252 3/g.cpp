#include<bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long

using namespace std;

ll n;
//vector<ll> is_prime(n+1, 1);
ll is_prime[21000];
vector<ll> prime;

void seive()
{
    is_prime[0] = is_prime[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i]==0 && (long long)i * i <= n)
        {
//            prime.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = 1;
        }
    }
    for(int i=1;i<11000;i++)
    {
        if(is_prime[i]==0) prime.push_back(i);
    }
    return;
}

ll f[21000];

int main()
{
    n=11000;
    seive();



    ll a, b;
    cin>>a>>b;
    ll ct=0;
    for(ll i=1;prime[i]<a;i++)
    {
        ll x=prime[i]+prime[i-1]+1;
        if(is_prime[x]==0) f[x]=1;
    }

    for(ll i=2;i<=a;i++)
    {
        if(f[i]==1) ct++;
//        cout<<f[i]<<endl;
    }
    if(ct>=b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}
