#include<bits/stdc++.h>
#define sz 100

using namespace std;
int p[sz], score[sz+1];
bool c[sz+1];

void seive()
{
    for(int i=2;i*i<=sz;i++)
    {
        if(c[i]==0)
        {
            for(int j=i+i;j<=sz;j=j+i)
                c[j]=1;
        }
    }
    int j=0;
    for(int i=2;i<=sz;i++)
    {
        if(c[i]==0)
        {
            p[j++]=i;
//            cout<<i<<endl;
        }
    }
    return;
}

int  sc(int n)
{
    if(c[n]==0) return (n-1)*(n-1);
    double x=(double) n;
    for(int i=0;p[i]<n;i++)
    {
        if(n%p[i]==0)
        {
        x=x*(1.0-1.0/p[i]);
        }
    }
    return (int)x*x;
}

void scall()
{
    score[2]=1;
    for(int i=3;i<=sz;i++)
    {
        score[i]=score[i-1]+sc(i);
    }

    return;
}

int main()
{
    seive();
    scall();
    cout<<score[20]-score[2]<<endl;
   int t;
   scanf("%d", &t);
   for(int i=1;i<=t;i++)
   {



   }

    return 0;
}

