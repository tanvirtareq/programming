#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;
ll ar[1000000], f[10000000], s1[10000000];
vector<ll> v;

int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>ar[i], s1[i]=s1[i-1]+ar[i];
    ll s=s1[n];
    if(s%3!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    s=s/3;
    ll ct=0;
//    ll ct=ar[1];
//    f[1]=0;

    for(int i=1;i<=n;i++)
    {
        ct+=ar[i];
        if(s1[i]==s) f[i]=1+f[i-1];
        else f[i]=f[i-1];
    }
    ll ans=0;
    ct=0;
    for(int i=n;i>1;i--)
    {
        ct+=ar[i];
        if(s1[i]==2*s)
        {
            ans+=f[i-1];
        }
    }
    if(s!=0)
    cout<<ans<<endl;
    else cout<<(f[n]-2)*(f[n]-1)/2<<endl;

    return 0;
}
