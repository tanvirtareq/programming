#include<bits/stdc++.h>
#define sz 100000
#define psz 9599
#define m 1000000007
typedef long long int llu;

using namespace std;

bool spf[sz+1];
llu p[psz];

void find_spf()
{
    spf[1]=1;

    for(llu i=2;i*i<=sz;i++)
    {
        if(spf[i]==0)
        {
            for(llu j=i*i;j<=sz;j=j+i)
                if(spf[j]==0) spf[j]=1;
        }

    }

    for(llu i=1, j=0;i<=sz;i++)
        if(spf[i]==0)
    {
        p[j]=i;
//        cout<<i<<endl;
        j++;
    }

    return;

}

llu power(llu b, llu pw)
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

llu bigmod(llu b, llu pw)
{
    if(pw==0)return 1;
    else if(pw==1) return b%m;
    else if(pw%2==0)
    {
        llu x=bigmod(b, pw/2)%m;
        return ((x%m)*(x%m))%m;
    }
    else
    {
        llu x=bigmod(b, pw/2)%m;
        return ((((b%m)*(x%m))%m)*(x%m))%m;
    }

}

llu sum(llu r, llu n)
{
//    llu pw=power(r, n+1);
//    llu ans=(pw-1)/(r-1);
//
    llu x=((((bigmod(r, n+1)%m)-1+m)%m)*(bigmod(r-1, m-2)%m)%m);

    return x;

}

llu cal(llu n, llu pw)
{
    llu ans=1;
    for(llu i=0;p[i]*p[i]<=n;i++)
    {
        llu cnt=0;
        while(n%p[i]==0)
        {
            cnt++;
            n=n/p[i];
        }
        if(cnt!=0)
        ans=((ans%m)*(sum(p[i], cnt*pw))%m)%m;

    }
    if(n>1)
    {
        ans=((ans%m)*(sum(n, pw))%m)%m;
    }
    return ans;
}

llu naivesumofdig(llu n)
{
    llu s=0;
    for(llu i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            s=s+i;
        }
    }
    return s;

}

int main()
{
//    prlluf("%d", sizeof(llu));
//    cout<<naivesumofdig(144)<<endl;
//    cout<<sum(2,2)<<endl;
//    cout<<sum(3,2)<<endl;
    find_spf();
//    cout<<cal(12, 2)<<endl;
    llu t, n, p;
    cin>>t;
    for(llu i=1;i<=t;i++)
    {
        cin>>n>>p;
        llu res=cal(n, p);
        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}
