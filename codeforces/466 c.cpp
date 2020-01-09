#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll ar[1000000];
vector<ll> v;

int main()
{
    ll n;
    cin>>n;
    ll s=0;
    for(ll i=1;i<=n;i++) cin>>ar[i], s+=ar[i];
    if(s%3!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    s=s/3;
    ll ct=0;
    ll f=0;
    for(ll i=1;i<=n;i++)
    {
        if(f)
        {
            v.push_back(ar[i]);
            continue;
        }
        ct+=ar[i];
        if(ct==s)
        {
            f=1;
        }
    }
    ct=0;

    while(v.size())
    {
        ct+=v.back();
        if(ct==s)
        {
            v.pop_back();
            break;
        }
        v.pop_back();
    }

    if(v.size()==0)
    {
        cout<<0<<endl;
        return 0;
    }

    ll k=v.size()-1;
    ct=0;
    for(ll i=k;i>0;i--)
    {
        ct+=v[i];
        if(s==ct)
        {
            k=i;
            break;
        }
    }
    ll x=1, y=1;
    ll l=INT_MAX;

    ct=0;
    for(ll i=0;i<k;i++)
    {
        ct+=v[i];
        if(ct==s)
        {
            l=min(l, i);
        }
        if(ct==0)
        {
            x++;
        }
    }

    ct=0;

    for(ll i=v.size()-1;i>l;i--)
    {
        ct+=v[i];
        if(ct==0) y++;
    }

    cout<<x*y<<endl;

    return 0;
}

