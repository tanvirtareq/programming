#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k1, k2;
        cin>>n>>k1>>k2;
        ll mx1=0, mx2=0;
        while(k1--)
        {
            ll x;
            cin>>x;
            mx1=max(mx1, x);
        }

        while(k2--)
        {
            ll x;
            cin>>x;
            mx2=max(mx2, x);
        }
        if(mx1>mx2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

