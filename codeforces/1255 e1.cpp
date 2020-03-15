#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl

using namespace std;

vector<ll> v;

ll chk(ll st, ll ed)
{
    if(st==ed) return 0;
    if(abs(st-ed)==1) return abs(v[st]-v[ed]);
    ll md=(st+ed)/2;
    if(st!=ed) md++;
    ll ct=0;
    for(ll i=st;i<=ed;i++)
    {
        ct+=abs(v[i]-v[md]);
    }
    return ct;
}


int main()
{
    ll n=100;
//    cin>>n;
    n=100000;
    ll ct=0;

    for(ll i=1;i<=n;i++)
    {
        ll x=1;
        if(x==1) v.push_back(i);
    }
    ll q=v.size();
    if(q<=1){
        cout<<-1<<endl;
        return 0;
    }
//    if(q==n){
//        cout<<n/2<<endl;
//        return 0;
//    }
    ct=v.size();
    for(ll i=2;i*i<=ct;i++)
    {
        if(ct%i==0)
        {
            q=i;
        }
    }
    ll i=0;
    ct=0;

    while(i<v.size())
    {
        ct+=chk(i, i+q-1);
        i+=q;
    }

    cout<<ct<<endl;

}
