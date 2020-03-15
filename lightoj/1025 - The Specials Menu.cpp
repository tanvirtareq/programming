#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dpt[100][100];

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

ll dpf(ll st, ll ed)
{
    if(st==ed)
    {
        return 1;
    }

    if(dpt[st][ed]!=-1) return dpt[st][ed];

    ll ans=0;
    ans+=dpf(st+1, ed);
    ans+=dpf(st, ed-1);
    if(s[st]==s[ed]) ans+=dpf(st+1, ed-1);

    return dpt[st][ed]=ans;
}

int main()
{
    ll t;
    scanf("%lld", &t);

    for(ll in=1;in<=t;in++)
    {

        memset(dpt, -1, sizeof dpt);
        cin>>s;
        printf("Case %lld: %lld\n", in, dpf(0, s.size()-1));

    }

    return 0;
}

