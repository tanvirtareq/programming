#include<bits/stdc++.h>
using namespace std;
int t, n,g[1510][1510], xr;
int dx[]={1, -1, -1, -2, -3, -2};
int dy[]={-2, -3, -2, -1, -1, 1};
int inline grn(int x, int y, int cs)
{
    if(g[x][y]!=-1) return g[x][y];
    map<int, int> mp;
    for(int i=0;i<6;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0 and yy>=0) mp[grn(xx, yy, cs)]=1;
    }
    for(int i=0;;i++)
        if(mp[i]==0)
        {
            return g[x][y]=i;
        }
}
int main()
{
    scanf("%d", &t);
    memset(g, -1, sizeof g);
    for(int in=1;in<=t;in++)
    {
        scanf("%d", &n);
        xr=0;
        int x, y;
        for(int i=1;i<=n;i++){
            scanf("%d%d", &x, &y);
            xr^=grn(x, y, in);
        }
        printf("Case %d: ", in);
        if(xr) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
