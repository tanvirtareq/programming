#include<bits/stdc++.h>
#define mxx 100000000
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x1, x2, y1, y2;
    cin>>n>>x1>>y1>>x2>>y2;

    if(x1==x2 and y1==y2)
    {
        cout<<0<<endl;
        return 0;
    }

    vector<pair<ll, pair<ll,ll> > > v;
    if(x1==0 and y1==0 || x2==0 and y2==0)
    {
        v.push_back({1, {0, 0}});
    }
    else v.push_back({0, {0, 0}});

    if(y1==0 and x1>0) v.push_back({1, {x1, y1}});
    if(y2==0 and x2>0) v.push_back({1, {x2, y2}});

    v.push_back({0, {n, 0}});

    if(x1==n and y1>0) v.push_back({1, {x1, y1}});
    if(x2==n and y2>0) v.push_back({1, {x2, y2}});

    v.push_back({0, {n, n}});

    if(y1==n and x1<n ) v.push_back({1, {x1, y1}});
    if(y2==n and x2<n ) v.push_back({1, {x2, y2}});

    v.push_back({0, {0, n}});

    if(x1==0 and y1<n) v.push_back({1, {x1, y1}});
    if(x2==0 and y2<n) v.push_back({1, {x2, y2}});

    int i=0;
    for(;i<v.size();i++)
    {
        if(v[i].first==1) break;
    }
//    cout<<i<<endl;
    pair<ll, ll> p=v[i].second;
    ll d=0;
    i++;
    for(;i<v.size();i++)
    {
        pair<ll, ll> q=v[i].second;

        if(p.first==q.first) d+=abs(p.second-q.second);
        else if(p.second==q.second) d+=abs(p.first-q.first);

        if(v[i].first==1) break;
        p=q;
    }

    cout<<min(d, 4*n-d)<<endl;

    return 0;
}




