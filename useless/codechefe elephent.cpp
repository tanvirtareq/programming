#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long int n, i;

    scanf("%lld", &n);

    long long int a[n];

     long long int count=0;
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
    }

//    prlong long intf("%lld", i);

    long long int c1=-1, c2=-1,k=-1, temp;

    for(i=1;i<n;i++)
    {
        if(a[i-1]==a[i]&&k==-1)
        {


            k=i-1;

//            prlong long intf("k=%lld\n", k);
        }

        if(c1==-1&&a[i-1]>a[i])
        {


            c1=i-1;
            if(k!=-1) c1=k;

            c2=i;

//            prlong long intf("k=%lld\nc1=%lld\nc2=%lld\n", k, c1, c2);
        }

        if(k!=-1&&a[i-1]!=a[i]) k=-1;

       else if(c1!=-1&&a[i]<a[c1])
        {
            c2=i;

//            prlong long intf("c2=%lld\n", c2);

        }


    }

    if(c1!=-1&&c2!=-1)
    {



    temp=a[c1];

    a[c1]=a[c2];
    a[c2]=temp;

    }

    for(i=1;i<n;i++)
    {
        if(a[i-1]>a[i]&&a[n-1!=32])
        {
            printf("NO\n");
            return 0;
        }


    }

    printf("YES\n");


    return 0;
}
