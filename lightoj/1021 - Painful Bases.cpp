#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dpt[1<<17][20];

ll power(ll b, ll p, ll md)
{
    if(p==0) return 1;
    if(p==1) return b;

    ll x=power(b, p/2, md)%md;
    x=(x*x)%md;
    if(p&1)
        x=(x*b)%md;

    return x;
}

ll val(char ch)
{
    if(ch<='9') return (ll)(ch-'0');
    else return (ll)(ch-'A'+10);
}

ll base, k;
 string s;

ll dpf(ll dg,ll md)
{
    ll pos=__builtin_popcount(dg);
    if(pos==s.size())
    {
        return (md==0);
    }
    if(dpt[dg][md]!=-1)
        return dpt[dg][md];

    ll ans=0;

    for(ll i=0;i<s.size();i++)
    {
        if(dg&(1<<i)) continue;
        ans=ans+dpf(dg|(1<<i), (md*base+val(i))%k);
    }
    return dpt[dg][md]=ans;
}

int main()
{
    ll t;
    scanf("%lld", &t);

    for(ll in=1;in<=t;in++)
    {

        memset(dpt, -1, sizeof dpt);

        scanf("%lld%lld", &base,&k);

        cin>>s;
        printf("Case %lld: %lld\n", in, dpf(0, 0));

    }

    return 0;
}
