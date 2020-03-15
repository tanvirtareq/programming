#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v;
        for(int i=1;i<=2*n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        cout<<v[n]-v[n-1]<<endl;

    }

    return 0;
}
