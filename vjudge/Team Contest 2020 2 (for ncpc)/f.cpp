#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mx 200009
map<ll,vector<ll>> mp;
ll n,m,i,j,k,l,t,par[mx],arr[mx],brr[mx],crr[mx],q;
ll find_par(ll node)
{
    return par[node]=(par[node]==node?node:find_par(par[node]));
}
int main()
{
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
        for(i=1; i<=n; i++)
            par[i]=i;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&q);
        for(j=1; j<=q; j++)
        {
            scanf("%lld",&l);
            mp[l].push_back(i);
        }
    }
    for(auto it : mp)
    {
        l=it.second.size();
        //vector<ll>v;
        t=it.second[0];
        for(j=1; j<l; j++)
        {
            k=it.second[j];
            {
                ll p=find_par(k);
                ll q=find_par(t);
                if(p!=q)
                {
                    arr[m]=k;
                    brr[m]=t;
                    crr[m]=it.first;
                    m++;
                    par[p]=q;
                }
            }
        }
    }
    l=find_par(1);
    for(i=2; i<=n; i++)
    {
        k=find_par(i);
        if(k!=l)
        {
            printf("impossible\n");
            return 0;
        }
    }
    for(i=0; i<m; i++)
    {
        printf("%lld %lld %lld\n",arr[i],brr[i],crr[i]);
    }
}

