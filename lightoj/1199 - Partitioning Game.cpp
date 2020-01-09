#include<bits/stdc++.h>
using namespace std;
int t, n, ar[200],g[20000], xr;
int grn(int x)
{
    if(g[x]!=-1) return g[x];
    if(x<=2) return 0;
    map<int, int> mp;
    for(int i=1;i<=x/2;i++)
        if(i!=x-i)
            mp[grn(i)^grn(x-i)]++;
    for(int i=0;;i++)
        if(mp[i]==0) return g[x]=i;
}
int main()
{
    scanf("%d", &t);
    memset(g, -1, sizeof g);
    for(int in=1;in<=t;in++)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%d", &ar[i]);
        xr=0;
        for(int i=1;i<=n;i++)
            xr^=grn(ar[i]);
        printf("Case %d: ", in);
        if(xr) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
