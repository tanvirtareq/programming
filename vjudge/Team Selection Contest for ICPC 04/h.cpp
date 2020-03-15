#include<bits/stdc++.h>

using namespace std;

int n, m;
vector< vector< int> > g;
vector<vector<int> > gr, components;
vector<int> order, v;
vector<bool> used;
set<int> s;

int dfs1(int rt)
{
    used[rt]=1;

    for(size_t i=0;i<g[rt].size();++i)
    {
        if(!used[g[rt][i]]) dfs1(g[rt][i]);


    }
    order.push_back(rt);
    return 0;
}

int dfs2(int rt, int ct)
{
    used[rt]=1;
    components[ct].push_back(rt);

    for(size_t i=0;i<gr[rt].size();++i)
        if(!used[gr[rt][i]]) dfs2(gr[rt][i], ct);

    return 0;

}

int dfs3(int rt)
{
    used[rt]=1;
    s.insert(rt);

    for(size_t i=0;i<g[rt].size();++i)
    {
        if(!used[g[rt][i]]) dfs3(g[rt][i]);
    }
    return 0;
}


int find_SCC()
{
    used.assign(n+10, false);

    for(int i=1;i<=n;i++)
        if(!used[i]) dfs1(i);

    used.assign(n+10, false);
    int ct=0;
    for(int i=0;i<n;i++)
    {
        int x=order[n-i-1];
        if(!used[x])
        {
            dfs2(x, ct);
            ct++;
        }

    }

    return 0;
}

int main()
{
    while(cin>>n>>m)
    {
        if(n==0 && m==0) return 0;

        for(int i=1;i<=m;i++)
        {

            int x, y;
            cin>>x>>y;
//            cout<<"fd"<<endl;
            g[x].push_back(y);
            gr[y].push_back(x);
//            cout<<x<<endl;
        }

        find_SCC();

        for(int i=0;i<components.size();i++)
        {

            for(int j=0;j<components[i].size();j++)
            {
                if(gr[components[i][j]].size()>1) v.push_back(components[i][j]);

            }
        }

        used.assign(n+10, false);

        for(int i=0;i<v.size();i++)
        {
            if(used[i]==0) dfs3(v[i]);

        }

        cout<<s.size()<<endl;
        s.clear();
        v.clear();
        components.clear();
        g.clear();
        gr.clear();
        order.clear();
        used.clear();

    }

}
