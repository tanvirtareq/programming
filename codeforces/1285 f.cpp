#include<bits/stdc++.h>
#define MX 3000000
#define Mxn 2000000000
using namespace std;
int t, n, x, y, ed1[MX], par[MX],vis[MX];;
vector<pair<int, int> > v;
vector<vector<int> > chl;
int un(int a, int b)
{
    if(a>=b) return 1;
    return 0;
}
int ch(int i, int j)
{
    if(un(v[i].second, v[j].first)) return 1;
    return 0;
}
int ch1(int i, int j)
{
    if(un(ed1[i], v[j].first)) return 1;
    return 0;
}
void make_tree(int r, int cs)
{
    if(r>=n) return;
    par[r]=-1;
    ed1[r]=v[r].second;
    int j=r+1;
    if(j>=n) return;
    stack<int> q;
    q.push(r);
    vis[r]=cs;
    while(!q.empty())
    {
        r=q.top();
        if(ch(r,j)==0)  q.pop();
        else
        {
            chl[r].push_back(j);
            par[j]=r;
            ed1[j]=max(v[j].second, ed1[r]);
            q.push(j);
            vis[j]=cs;
            j++;
        }
        if(j>=n) return;
    }
}
int fnd(int r)
{
    if(par[r]==-1) return chl[r].size()-1;
    int p=par[r], ct=0;
    for(int i=0;i<chl[r].size();i++)  if(ch1(p, chl[r][i])==0) ct++;
    return ct;
}
int main()
{
    cin>>t;
    while(t--)
    {
        v.clear();
        chl.clear();
        cin>>n;
        chl.resize(n+10);
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            v.push_back({min(x, y), max(x, y)});
        }
        sort(v.begin(), v.end());
        int ct=0;
        for(int i=0;i<v.size();i++) if(vis[i]!=t+1) make_tree(i, t+1), ct++;
        int mx=-Mxn;
        for(int i=0;i<v.size();i++) mx=max(mx, fnd(i));
        cout<<mx+ct<<endl;
    }
    return 0;
}
