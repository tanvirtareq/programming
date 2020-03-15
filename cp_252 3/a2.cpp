#include<bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long

using namespace std;

ll n;
//vector<ll> is_prime(n+1, 1);
ll is_prime[2100000];
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
    for(int i=1;i<1100000;i++)
    {
        if(is_prime[i]==0) prime.push_back(i);
    }
    return;
}
ll ar[1000][1000];

int main()
{
    n=1100000;
    seive();

    ll a, b;
    cin>>a>>b;

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            ll x;
            cin>>x;
            for(int k=0;;k++)
            {
                if(is_prime[x+k]==0)
                {
                    ar[i][j]=k;
                    break;
                }
            }
        }
    }

    ll ct=0;
    ll mn=LLONG_MAX;

    for(int i=1;i<=a;i++)
    {
        ct=0;
        for(int j=1;j<=b;j++)
        {
            ct+=ar[i][j];
        }
        mn=min(mn, ct);
    }

    for(int i=1;i<=b;i++)
    {
        ct=0;
        for(int j=1;j<=a;j++)
        {
            ct+=ar[j][i];
        }
        mn=min(mn, ct);
    }

    cout<<mn<<endl;


    return 0;
}

