#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    int lr[n+10], rr[n+10], ar[n+10];
    for(int i=1;i<=n;i++) cin>>ar[i];
    lr[1]=ar[1];
    for(int i=2;i<=n;i++)
    {
        lr[i]=lr[i-1]|ar[i];
//        cout<<i<<" "<<lr[i]<<endl;
    }
    rr[n]=ar[n];

    for(int i=n-1;i>=1;i--)
    {
        rr[i]=ar[i]|rr[i+1];
    }

    pair<int, int> p;
    p={-1, -1000100000};

    lr[0]=rr[n+1]=0;

    for(int i=1;i<=n;i++)
    {
        int l=lr[i-1];
        int r=rr[i+1];
        int fc=l|r;

        int m=(ar[i]|fc)-fc;
//        cout<<i<<" "<<m<<endl;
        if(m>=p.second)
        {
            p.first=i;
            p.second=m;
//            cout<<p.first<<" a;ldj "<<p.second<<endl;
        }
    }
    if(p.first!=-1)
    cout<<ar[p.first]<<" ";

    for(int i=1;i<=n;i++)
    {
        if(i!=p.first) cout<<ar[i]<<" ";
    }

    return 0;
}

