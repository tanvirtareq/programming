#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned n, k, m, d, x,ans;

    scanf("%llu%llu%llu%llu", &n, &k, &m ,&d);

    if(d>1)
        {
        long long unsigned  temp=(k-1)*(d-1)+d;

        printf("temp=%llu\n", temp);

        x=n/temp;

        printf("x=%llu\n", x);

        if(x<=m&&x!=0)
        {
            ans=d*x;

//            printf("%llu", ans);
        }

        else if(x>m&&m*d<=n)
        {
            ans=m*d;

//            printf("%llu", ans);
        }

        else if(x==0) ans=m;

        else ans=n;
    }



    else if(d<=1)
    {


    ans =m;

        if(ans>n) ans=m;
    }

//    if(ans==0) ans=m;

    printf("%llu",ans);


    return 0;
}


/// 1000000000000000000 135 1000000000000000 1000
