#include<bits/stdc++.h>
#define mxx 100000000
using namespace std;
//int t, n, ar[2000],g[mxx], xr;
//int grn(int x)
//{
//    if(x<mxx and g[x]!=-1) return g[x];
//    if(x<=1) return 0;
//    map<int, int> mp;
//    for(int i=1;i<=x/2;i++)
//            mp[grn(x-i)]++;
//    for(int i=0;;i++)
//        if(mp[i]==0) return (x<mxx)? g[x]=i: i;
//}
int grn2(int x)
{
    return (x&1)? grn2(x/2):x/2;
}
int main()
{
    int t;
    scanf("%d", &t);
//    memset(g, -1, sizeof g);
//    for(int i=0;i<100;i++)
//    {
//        if(i%2)
//        cout<<i<<" "<<grn(i)<<endl;
//    }
    for(int in=1;in<=t;in++)
    {
        int n;
        scanf("%d", &n);
        int xr=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d", &x);
            xr^=grn2(x);
        }


        printf("Case %d: ", in);
        if(xr) puts("Alice");
        else puts("Bob");
    }
    return 0;
}

