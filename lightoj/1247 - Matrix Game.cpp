#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for(int in=1;in<=q;in++)
    {
        int n,m,  xr=0, x;
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
        {
            x=0;
            for(int j=1;j<=m;j++)
            {
                int y;
                scanf("%d", &y);
                x+=y;
            }
            xr^=x;
        }

         printf("Case %d: ", in);
        if(xr==0) puts("Bob");
        else puts("Alice");
    }
    return 0;
}


