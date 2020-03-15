#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;
ll ar[1000000], f[10000000], s1[10000000];
vector<ll> v;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll s=0;
        ll s2=0;
        ll f=0;
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            ar[i]=x;
            s+=x;
            if(s2+x<=0) f=1, s2=0;
            else s2+=x;
        }
        ll s3=0;
        for(int i=n;i>0;i--)
        {
            if(s3+ar[i]<=0) f=1, s3=0;
            else s3+=ar[i];
        }

        if(f==0)
        {
            cout<<"YES"<<endl;

        }
        else
        {
            if(max(s3, s2)<s)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


