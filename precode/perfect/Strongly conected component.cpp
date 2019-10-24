/**
problem link
https://vjudge.net/problem/UVALive-7822

*/



#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> g[51000];
vector<int> gr[51000], components[51000];
vector<int> order, v;
vector<bool> used, vis;
set<int> s;
int ct;

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

int dfs2(int rt)
{
    used[rt]=1;
    components[ct].push_back(rt);

    for(size_t i=0;i<gr[rt].size();++i)
        if(!used[gr[rt][i]]) dfs2(gr[rt][i]);

    return 0;

}

int dfs3(int rt)
{
    used[rt]=1;
    s.insert(rt);

    for(size_t i=0;i<gr[rt].size();++i)
    {
        if(!used[gr[rt][i]]) {
                dfs3(gr[rt][i]);
        v.push_back(gr[rt][i]);
        }
    }
    return 0;
}


int find_SCC()
{
    used.assign(n+10, false);

    for(int i=1;i<=n;i++)
        if(!used[i]) dfs1(i);

    used.assign(n+10, false);
    ct=0;
    for(int i=0;i<n;i++)
    {
        int x=order[n-i-1];
        if(!used[x])
        {
            dfs2(x);
            ct++;
//            cout<<ct<<endl;
        }

    }
//    cout<<ct<<endl;

    return 0;
}

bool chk(vector<int> v)
{
    int ck=0;
    for(int i=0;i<v.size();i++)
    {
        if(vis[v[i]]) ck++;
        if(ck>=2) return 1;
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
            g[x].push_back(y);
            gr[y].push_back(x);
        }

        find_SCC();
        vis.assign(n+10, 0);
        for(int i=0;i<ct;i++)
        {
            if(components[i].size()>=2)
            {
                for(int j=0;j<components[i].size();j++)
                {
                    vis[components[i][j]]=1;
                }

            }

        }

        for(int i=0;i<ct;i++)
        {

            for(int j=0;j<components[i].size();j++)
            {
                if(gr[components[i][j]].size()>1  and chk(gr[components[i][j]])) v.push_back(components[i][j]);
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
        for(int i=0;i<51000;i++)
        {
            components[i].clear();
            g[i].clear();
            gr[i].clear();

        }
        order.clear();
        used.clear();
        vis.clear();

    }

}


/**

3 3
1 2
2 3
3 1

5 6
1 2
2 3
3 1
3 4
4 5
5 3

4 5
1 2
2 3
3 2
3 2
3 4
0 0

*/
