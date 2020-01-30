#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for(int in=1;in<=q;in++)
    {
        int n,m,  xr=0, x;
        scanf("%d", &n);
        int f=0, ct=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &x);
            if(x!=1) f=1;
            if(x==1) ct++;
            xr^=x;
        }

         printf("Case %d: ", in);
         if(f==0)
         {
             if(ct%2!=0) puts("Bob");
             else puts("Alice");
             continue;
         }
        if(xr==0) puts("Bob");
        else puts("Alice");
    }
    return 0;
}



