#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned n, k, m, d, x,ans;

    scanf("%llu%llu%llu%llu", &n, &k, &m ,&d);

    if(d>1)
        {
        long long unsigned  temp=(k-1)*(d-1)+d;

        x=n/temp;

        if(x<=m)
        {
            ans=d*x;

//            printf("%llu", ans);
        }

        else
        {
            ans=m*d;

//            printf("%llu", ans);
        }
    }



    else if(d<=1)
    {


    ans =m;
    }

    if(ans==0) ans=m;

    printf("%llu",ans);


    return 0;
}
