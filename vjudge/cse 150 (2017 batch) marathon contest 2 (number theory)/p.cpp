#include<bits/stdc++.h>
#define sz 100000000
#define psz 5761455
#define m 1000000007
//typedef long long unsigned llu;

using namespace std;

bool spf[sz+1];
int p[psz];

void find_spf()
{
    spf[1]=1;

    for(int i=2;i*i<=sz;i++)
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
//        cout<<i<<endl;
        j++;
    }
//    cout<<j<<endl;

    return;

}

int power(short b, short pw)
{
    if(pw==0)return 1;
    else if(pw==1) return b;
    else if(pw%2==0)
    {
        int x=power(b, pw/2);
        return x*x;
    }
    else
    {
        int x=power(b, pw/2);
        return b*x*x;
    }

}

int sum(short r, short n)
{
    int pw=power(r, n+1);
    pw=(pw-1)/(r-1);

    return pw%m;

}

int cal(short  n, short pw)
{
    int ans=1;
    for(int i=0;p[i]<=n;i++)
    {
        short cnt=0;
        while(n%p[i]==0)
        {
            cnt++;
            n=n/p[i];
        }
        if(cnt!=0)
        ans=(ans*sum(p[i], cnt*pw))%m;

    }
    return ans;
}
//
//int naivesumofdig(int n)
//{
//    int s=0;
//    for(int i=1;i<=n;i++)
//    {
//        if(n%i==0)
//        {
//            s=s+i;
//        }
//    }
//    return s;
//
//}

int main()
{
    printf("%d", sizeof(short));
//    cout<<naivesumofdig(144)<<endl;
//    cout<<sum(2,2)<<endl;
//    cout<<sum(3,2)<<endl;
    find_spf();
//    cout<<cal(12, 2)<<endl;
    short int t, n, p;
    cin>>t;
    for(short int i=1;i<=t;i++)
    {
        cin>>n>>p;
        int res=cal(n, p);
        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}

