#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned k, n, s, p, ans;

    scanf("%llu%llu%llu%llu", &k, &n, &s, &p);

    ans=ceil((double)k*ceil((double)n/s)/p);

    printf("%llu", ans);

    return 0;
}
