#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q;
    scanf("%lld", &q);
    for(long long in=1;in<=q;in++)
    {
        long long n, xr=0;
        scanf("%lld", &n);
        long long ar[n+10];
        for(long long i=1;i<=n;i++)
            scanf("%lld", &ar[i]);
        for(long long i=1;i<=n;i++)
        {
            long long x;
            scanf("%lld", &x);
            ar[i]=abs(ar[i]-x)-1;
            xr^=ar[i];
        }
        printf("Case %lld: ", in);
        if(xr==0)
            puts("black wins");
        else puts("white wins");
    }
    return 0;
}
