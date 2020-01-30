#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<" = "<<a<<endl
using namespace std;
ll vis[2000000], pabe[100010], dibe[100010], x, y, w,  ct, tmp,ansct;
vector<pair<ll, ll> > vpabe, vdibe;
vector<pair<pair<ll, ll> , ll > > vp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        dibe[x]+=w;
        pabe[y]+=w;
    }
    for(ll i=1;i<=n;i++)
    {
        tmp=dibe[i]-pabe[i];
        if(tmp>0) {
                ct+=tmp;
                vdibe.push_back({tmp, i});
        }
        else if(tmp<0)
        {
            vpabe.push_back({-tmp, i});
        }
    }
    sort(vdibe.begin(), vdibe.end());
    sort(vpabe.begin(), vpabe.end());
    while(ct>0 and vdibe.size() and vpabe.size())
    {
        ll z=min(ct, min(vdibe.back().first, vpabe.back().first));
        ct-=z;
        vdibe.back().first-=z;
        vpabe.back().first-=z;
        vp.push_back({{vdibe.back().second, vpabe.back().second}, z});
        if(vdibe.back().first<=0) vdibe.pop_back();
        if(vpabe.back().first<=0) vpabe.pop_back();
        if(ct<=0) break;
    }
    cout<<vp.size()<<endl;
    for(ll i=0;i<vp.size();i++)
    {
        cout<<vp[i].first.first<<" "<<vp[i].first.second<<" "<<vp[i].second<<endl;
    }
    return 0;
}
