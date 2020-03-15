#include<bits/stdc++.h>
#define MX 200000
#define ll long long
using namespace std;
ll a[MX], n, dpt[MX],y;
vector<ll> v;
ll dp(ll i)
{
    if(i>=v.size()) return 0;
    ll x=v[i];
    if(i==v.size()-1) return x*a[x];
    if(dpt[i]!=-1) return dpt[i];
    ll p=0, q=0;
    if(v[i+1]-1==x)
    {
        q=dp(i+2)+x*a[x];
        p=dp(i+1);
    }
    else {
        q=dp(i+1)+x*a[x];
    }
    return dpt[i]=max(p, q);
}
int main()
{
    cin>>n;
    memset(dpt, -1, sizeof dpt);
    for(ll i=1;i<=n;i++)
    {
        cin>>y;
        a[y]++;
        if(a[y]==1) v.push_back(y);
    }
    sort(v.begin(), v.end());
    cout<<dp(0)<<endl;
    return 0;
}

