#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"= "<<a<<endl
using namespace std;

int n, k;

ll dpt[100000][20];

ll dpf(int mask, int prv)
{
    ll ans=0;
    if(__builtin_popcount(mask)==n) return 1;

    if(dpt[mask][prv]!=-1) return dpt[mask][prv];
//    dbg(mask);
//    dbg(prv);
    int f=0;
    for(int i=1; i<=n; i++)
    {
        if(mask&(1<<i))
            continue;
        if(abs(prv-i)>k)
            continue;

        f=1;
        ans+=dpf(mask|(1<<i), i);
    }
//    if(f==0) return 1;
    return dpt[mask][prv]=ans;

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        ll ans=0;
        cin>>n>>k;
        memset(dpt, -1, sizeof dpt);
        for(int i=1; i<=n; i++)
        {

            ans+=dpf(1<<i, i);
        }
        cout<<ans<<endl;

    }

    return 0;

}
