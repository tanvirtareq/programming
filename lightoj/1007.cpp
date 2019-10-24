#include<bits/stdc++.h>
#define sz 5*1000000
using namespace std;

bool ch[sz+1];
int p[sz];
int s;

void seiveprime()
{
    for(int i=2;i*i<=sz;i++)
    {
        if(ch[i]=0)
            for(int j=i+i;j<=sz;j=j+i)
        {
            ch[j]=1;
        }
    }
    for(int i=2;i<=sz;i++)
    {
        if(ch[i]==0) p[++s]=i;
    }



    return;
}

int to[sz+1];

float totient(int n)
{
    float res=n;
    for(int i=1;p[i]<n;i++)
    {
        res=res*(1-1/(float)p[i]);
        cout<<res;
    }
    cout<<res<<endl;
    return res;

}

void totientall()
{
    to[1]=1;
    to[2]=1;
    to[3]=2;

    for(int i=4;i<=sz;i++)
    {
        to[i]=totient(i);
    }

    return;
}

int main()
{
    seiveprime();

//    totientall();

    int t, a, b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        float res=0;
        cin>>a>>b;
        for(int j=a;j<=b;j++)
        {
            res=res+totient(j);
        }
        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}
