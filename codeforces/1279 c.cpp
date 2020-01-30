#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define ii pair<ll, ll>
#define dbg(a) cout<<#a<<"="<<a<<endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>m>>n;
        map<ll, ll> mp;

        for(ll i=1;i<=m;i++)
        {
            ll x;
            cin>>x;
            mp[x]=i;
        }
        ll ct=0;
        ll fc=0;
        for(ll i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            ll k=mp[x]-i;
            if(mp[x]<=fc)
            {
                ct++;
            }
            else if(k<=0)
            {
                ct++;
                fc=max(fc, mp[x]);
            }
            else if(k>0)
            {
                ct+=2*k+1;
                fc=max(fc, mp[x]);
            }
            fc=max(fc, i);
//            cout<<ct<<endl;
        }
        cout<<ct<<endl;

    }

}

/**
1
7 3
2 1 7 3 4 5 6
3 1 2

1
7 3
2 1 7 3 4 5 6
3 1 6


1
7 3
2 1 7 3 4 5 6
3 2 6
*/



