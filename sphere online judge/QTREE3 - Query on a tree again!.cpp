#include<bits/stdc++.h>
#define N 100100
#define LN 20
#define ii pair<int, int>
using namespace std;

vector<int> adj[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[N], subsize[N], pos[N];
set<ii> sth[N];
void dfs(int cur, int prev, int _depth=0)
{
    pa[cur]=prev;
    depth[cur]=_depth;
    subsize[cur]=1;
    for(auto it: adj[cur])
    {
        if(it==prev)
            continue;
        dfs(it, cur, _depth+1);
        subsize[cur]+=subsize[it];
    }
}
void HLD(int curNode, int prev)
{
    if(chainHead[chainNo]==0)
        chainHead[chainNo]=curNode;

    chainInd[curNode]=chainNo;
    posInBase[curNode]=++ptr;
    int sc=-1;
    for(auto it:adj[curNode])
    {
        if(it!=prev)
        {
            if(sc==-1 || subsize[sc]<subsize[it])
            {
                sc=it;
            }
        }
    }
    if(sc!=-1)
        HLD(sc, curNode);

    for(auto it:adj[curNode])
    {
        if(it!=prev and sc!=it)
        {
            chainNo++;
            HLD(it, curNode);
        }
    }
}

int print(int v)
{
    int vchain=chainInd[v];
    if(vchain==0)
    {
        if(sth[vchain].size()==0)
            return 0;
        ii it=*sth[vchain].begin();
        if(it.first>posInBase[v]) return 0;
        printf("%d\n", it.second);
        return 1;
    }

    int u=chainHead[vchain];
    u=pa[u];
    if(print(u))
        return 1;
    if(sth[vchain].size()==0)
        return 0;
    ii it=*sth[vchain].begin();
    if(it.first>posInBase[v]) return 0;
    printf("%d\n", it.second);
    return 1;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1; i<n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    HLD(1, -1);
    while(q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a==0)
        {
            if(sth[chainInd[b]].find({posInBase[b], b})==sth[chainInd[b]].end())
            {
                sth[chainInd[b]].insert({posInBase[b], b});
            }
            else
                sth[chainInd[b]].erase({posInBase[b], b});

        }
        else if(print(b)==0)
            printf("-1\n");
    }
    return 0;
}
