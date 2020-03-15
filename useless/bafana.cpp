#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t, n, k, p, ans, i;

    scanf("%lld", &t);

    for(i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld", &n, &k, &p);

        ans=k+p%n;

        if(ans>n) ans=ans-n;

        printf("Case %lld: %lld\n", i, ans);


    }

    return 0;
}
