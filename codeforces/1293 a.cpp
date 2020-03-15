#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, s, k;
        cin>>n>>s>>k;
        map<ll, ll> v;
        for(ll i=1;i<=k;i++)
        {
            ll x;
            cin>>x;
            v[x]=1;

        }
        ll f;

        for(ll i=0;i<=n;i++)
        {
            if(s-i>0 and v[s-i]==0)
            {
                cout<<i<<endl;
                f=1;
                break;
            }
            if(s+i<=n and v[s+i]==0)
            {
                cout<<i<<endl;
                f=1;
                break;
            }
        }
    }

    return 0;
}
