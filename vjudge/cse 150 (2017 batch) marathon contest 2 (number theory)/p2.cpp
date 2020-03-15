#include<bits/stdc++.h>
#define sz 100000
#define psz 9599
#define m 1000000007
using namespace std;

typedef long long unsigned llu;

bool spf[sz+1];
int p[psz];

void find_spf()
{
    spf[1]=1;

    for(int  i=2;i*i<=sz;i++)
    {
        if(spf[i]==0)
        {
            for(int j=i*i;j<=sz;j=j+i)
                if(spf[j]==0) spf[j]=1;
        }

    }
    int j=0;
    for(int i=1;i<=sz;i++)
        if(spf[i]==0)
    {
        p[j]=i;
        j++;
    }
//    cout<<j<<endl;

    return;

}

llu power(llu  b,llu  pw)
{
    if(pw==0)return 1;
    else if(pw==1) return b;
    else if(pw%2==0)
    {
        llu x=power(b, pw/2);
        return x*x;
    }
    else
    {
        llu x=power(b, pw/2);
        return b*x*x;
    }

}

int main()
{
    find_spf();
    short t;
    llu  n, pw;
    cin>>t;
    for(short i=1;i<=t;i++)
    {
        cin>>n>>pw;

        llu ans=1;
        for(int j=0;p[j]*p[j]<=n;j++)
        {
            int cnt=0;
            while(n%p[j]==0)
            {
                cnt++;
                n=n/p[j];
            }
            cout<<p[j]<<"p[j] fot cnt "<<cnt<<endl;
            if(cnt!=0)
            {
//                llu pw1=power(p[j], cnt*pw+1);
////                cout<<pw1<<endl;
//                pw1=(power(p[j], cnt*pw+1)-1)/(p[j]-1);

                 ans=((ans%m)*((power(p[j], cnt*pw+1)-1)/(p[j]-1))%m)%m;
            }


        }
        if(n>1)
//            cout<<n<<endl;
        {
            ans=(ans*(power(n, pw+1)-1)/(n-1))%m;
        }

        cout<<"Case "<<i<<": "<<ans<<endl;
    }

    return 0;
}
