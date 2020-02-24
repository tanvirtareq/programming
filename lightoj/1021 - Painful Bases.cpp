#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dpt[80000][17][20];

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

ll dpf(ll dg, ll pos, ll md)
{
    md%=k;
    if(pos==s.size())
    {
        if(md==0) return 1;
        return 0;
    }

    if(dpt[dg][pos][md]!=-1) return dpt[dg][pos][md];

    ll pw=power(base, pos, k);
    ll ans=0;

    for(ll i=0;i<s.size();i++)
    {
        if(dg&(1<<i)) continue;
        dg^=(1<<i);
        ans=(ans+dpf(dg, pos+1, (md+(pw*val(i))%k)%k));
        dg^=(1<<i);
    }
//    cout<<pos<<" "<<ans<<endl;

    return dpt[dg][pos][md]=ans;
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
        printf("Case %lld: %lld\n", in, dpf(0, 0,0));

    }

    return 0;
}
