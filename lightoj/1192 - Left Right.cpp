#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for(int in=1;in<=q;in++)
    {
        int n, xr=0, x, a, b;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d", &a, &b);
            xr^=abs(a-b)-1;
        }

         printf("Case %d: ", in);
        if(xr==0) puts("Bob");
        else puts("Alice");
    }
    return 0;
}

