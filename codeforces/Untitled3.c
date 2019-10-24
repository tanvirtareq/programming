#include<stdio.h>
#define sz 100000000
typedef long long int lld;

 lld power(lld b, lld p)
{
    if(p==0) return 1;
    if(p==1) return b;

    if(p&1)
    {
        lld x=power(b, p/2);
        return b*x*x;
    }

    else{
        lld x=power(b, p/2);
        return x*x;
    }
}

lld prime[sz-10],  tp=0;
int chk[sz+10];

 void seieve()
{
    lld i, j;
    prime[tp++]=2;
    for(i=3;i<=sz;i+=2)
    {
        if(chk[i]==0)
        {
//            prime.push_back(i);
            prime[tp++]=i;
            for( j=i+i;j<=sz;j+=i)
            {
                chk[j]=1;
            }

        }
    }


}
 lld divs(lld y)
{
    lld x=y, i;
    lld sum=1;
    for( i=0;prime[i]*prime[i]<=x;i++)
    {
//        cout<<prime[i]<<"ads"<<endl;
        lld div=0;
        while(x%prime[i]==0)
        {
//            cout<<x<<endl;
            div++;
            x=x/prime[i];
//            cout<<div<<" "<<x<<" "<<prime[i]<<endl;
        }
        if(div!=0)
        {
//            cout<<sum<<endl;
           lld temp=(power(prime[i], div+1)-1)/(prime[i]-1);
//           cout<<temp<<endl;
           sum*=temp;

        }
    }

    lld temp=(power(x, 2)-1)/(x-1);
    sum*=temp;

    return sum-y;



}

int main()
{
    seieve();
    lld t, x;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &x);

        printf("%lld\n", divs(x));
    }
}
