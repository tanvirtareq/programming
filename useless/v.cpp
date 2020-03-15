#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned n, m,tp1,tp2 , ans;

    scanf("%llu%llu",&n, &m );

    tp1=ceil((double)n/2);

    if(n<m) {

            printf("-1");

    return 0;
    }

    tp2=tp1%m;

    if(tp2==0) ans=tp1;

    else
    ans=tp1+(m-tp2);

    printf("%llu", ans);



    return 0;
}
