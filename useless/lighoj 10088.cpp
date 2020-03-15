#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long int t, i, j, k, big, end, mid, count;

    long long int n, q, a, b, flag;

    scanf("%lld", &t);

    for(i=1;i<=t;i++)
    {
        printf("Case %lld\n", i);


        scanf("%lld%lld", &n, &q);

        long long int ar[n];

        for(j=0;j<n;j++)
        {
//            printf("j=%d\n", j);

            scanf("%lld", &ar[j]);

        }



        while(q--)
        {
            scanf("%lld%lld", &a, &b);

            big=0;
            end=n-1;

            flag=-1;

            count=0;

            while(big<end)
            {
                mid=(big+end)/2;

                if(ar[mid]==a)
                {
                    flag=mid;
                    break;
                }

                else if(ar[mid]<a) big=mid+1;

                else end=mid-1;

            }

            if(flag<0) flag=big;

            flag=flag-1;

            while(flag<n)
            {
                flag++;
                if(ar[flag]<=b)
                count=count+1;



                else break;

            }

            printf("%lld\n", count);

        }


    }


    return 0;
}
