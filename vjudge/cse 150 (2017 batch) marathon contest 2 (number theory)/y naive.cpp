#include<bits/stdc++.h>
#define sz 10000

using namespace std;
    map<int , int > mp;

    bool chk[sz+1];


int power(int b, int p)
{
    if(p<=0) return 1;
    else if(p==1) return b;
    else if(p%2==0)
    {
        int x=power(b, p/2);
        return x*x;
    }
    else
    {
        int x=power(b, p/2);
        return b*x*x;
    }
}

void fact(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
            cnt++;
            n=n/i;
//            cout<<i<<" ";
        }
//        cout<<endl;
//        if(chk[(power(i, cnt)-1)/(i-1)]==0) cout<<i<<" ";
    }
    return;

}


void seive()
{
    chk[0]=1;
    chk[1]=1;
    for(int i=2;i*i<=sz;i++)
    if(chk[i]==0)
        for(int j=i+i;j<=sz;j=j+i)
        chk[j]=1;

}

int main()
{
    seive();



    int t, l, h;
    cin>>t;
    while(t--)
    {
        cin>>l>>h;

        for(int i=l;i<=h;i++)
        {

        }
    }

    return 0;
}

