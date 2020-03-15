#include<bits/stdc++.h>
#define ll long long

using namespace std;
vector<ll> v2, v3;
vector<pair<ll, ll> > v;
ll adj[1100][1100];
int vis[1100];
map<ll, ll> vis2;
ll n;

int bfs(ll rt, ll d)
{
    int ct=0;
    queue<ll> q;

    q.push(rt);
    vis[rt]=1;
    ct++;
    v3.push_back(rt);
    while(!q.empty())
    {
        rt=q.front();
        q.pop();
        for(int i=0;i<v.size();i++)
        {
            if(vis[i]) continue;
            ll ch=i;
            if(adj[rt][ch]!=d) continue;

            vis[ch]=1;
            ct++;
            q.push(ch);
            v3.push_back(ch);
        }
    }
    if(ct==n) return 0;
    return 1;

}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }


    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            ll d=(v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
            adj[i][j]=d;
            adj[j][i]=d;
            v2.push_back(d);
        }
    }


    for(int i=0;i<v2.size();i++)
    {
        if(vis2[v2[i]]!=0) continue;

        vis2[v2[i]]=1;
        memset(vis, 0, sizeof vis);
        v3.clear();

        if(bfs(1, v2[i]))
        {
            if(v3.size()==2)
            {
                cout<<1<<endl<<v3[0]<<endl;
                return 0;
            }
            cout<<v3.size()<<endl;
            for(int i=0;i<v3.size();i++)
            {
                cout<<v3[i]+1<<" ";
            }
            break;
        }
    }

    return 0;
}
