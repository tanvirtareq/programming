#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rec(vector<ll> &v, int bit)
{
    if(v.size()==0 || bit<0) return 0;
    vector<ll> a, b;
    for(auto it:v)
    {
        if(it&(1<<bit))  a.push_back(it);
        else b.push_back(it);
    }
    if(a.size()!=0 and b.size()!=0)
    return min(rec(a, bit-1), rec(b, bit-1))+(1<<bit);
    if(a.size()!=0) return rec(a, bit-1);
    else return rec(b, bit-1);
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v) cin>>it;
    cout<<rec(v, 30)<<endl;
    return 0 ;
}
