#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" = "<<x<<endl

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        ll n;
        cin>>n;
        int ar[n+10];
        ar[0]=0;
        ar[n+1]=0;
        int mn=1000000000;
        int mx=-1;
        for(int i=1;i<=n;i++) cin>>ar[i];
        for(int i=1;i<=n;i++)
        {
            if(ar[i]!=-1 and (ar[i-1]==-1 or ar[i+1]==-1))N
            {
                mn=min(mn, ar[i]);
                mx=max(mx, ar[i]);
            }
        }


        ll mdm=(mn+mx)/2;

        mn=INT_MAX;
        mx=-10;

        for(int i=1;i<=n;i++)
        {
            if(ar[i]==-1) ar[i]=mdm;
            if(i==1) continue;
            int fc=abs(ar[i]-ar[i-1]);
            mx=max(mx, fc);
        }

        cout<<mx<<" "<<mdm<<endl;
    }

}


