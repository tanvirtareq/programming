#include<stdio.h>

int main()
{
    long long int  n, k, ans, f=1, mask;

    scanf("%lld %lld", &n, &k);
    mask=(f<<k)-1;

    ans=n|mask;
    while(ans<n)
    {
        mask=mask<<1;
        ans=n|mask;
    }

    printf("%lld\n", ans);

    return 0;
}
/**

364269800189924
33
*/



