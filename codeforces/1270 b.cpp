#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int ar[n+10];
        int mxl=0;
        ar[0]=0;
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            ar[i]=x;
            if(ar[i]>ar[mxl]) mxl=i;
        }
        ll f=0;

        for(int i=1;i<n;i++)
        {
            if(abs(ar[i]-ar[i+1])>=2)
            {
                f=1;
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<endl;
                break;
            }
        }

        if(f==0) cout<<"NO"<<endl;


    }
    return 0;
}


