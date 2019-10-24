#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, i, q, x, b,e, temp,  max,min;

    long long int t, m;

    scanf("%lld", &n);

    long long unsigned a[n];

    for(i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
    }

    scanf("%lld", &q);

    for(i=1;i<=q;i++)
    {
        scanf("%lld", &x);

        t=-1;


        b=0;

        e=n-1;

        while(b<=e&&b>=0&&e<=n-1)
        {
            m=(b+e)/2;

            if(a[m]==x)
            {
                t=m;

                break;

            }

            else if(a[m]>x) e=m-1;

            else b=m+1;


        }

//        printf("%lld  %lld  %lld\n", t, b, e);

        if(t<0)
        {
            if(e==-1) printf("X %lld\n", a[b]);

            else if(b>=n) printf("%lld X\n", a[e]);

            else printf("%lld %lld\n", a[e], a[b]);

        }

        else
        {
            temp=t;

            while(temp>=0)
            {

                temp--;
                if(a[temp]!=x)
                {
                    min=temp;
                    break;
                }

            }

            temp=t;

            while(temp<n)
            {
                temp++;

                if(a[temp]!=x)
                {
                    max=temp;
                    break;
                }

            }

            if(max<n&&min>=0) printf("%lld %lld\n", a[min], a[max]);

           else if(max>=n&&min>=0) printf("%lld X\n", a[min]);

            else if(max<n&&min<0) printf("X %lld\n", a[max]);


        }



    }
    return 0;
}
