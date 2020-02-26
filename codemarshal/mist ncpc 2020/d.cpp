#include<bits/stdc++.h>
#define MX 110000

using namespace std;

vector<int> g[110000], seq;
int st[MX], ed[MX], t[4*MX], ar[MX], n;

int tot;

void reset()
{
    for(int i=0;i<=n;i++) g[i].clear();
    seq.clear();
    tot=0;
}

void dfs(int rt, int p)
{
    st[rt]=seq.size();
    for(auto it:g[rt])
    {
        if(it!=p) dfs(it, rt);
    }
    seq.push_back(rt);
    ed[rt]=seq.size()-1;
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
        ar[tl]=new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void dlt(int v, int tl, int tr, int idx, int u)
{
    if(tl>ed[u]) return;
    if(tl==tr)
    {
        if(tl>ed[u]) return;
        t[v]=0;
        ar[tl]=0;
        tot--;
        return;
    }
    int tm = (tl + tr) / 2;
    if(t[2*v]>=idx) dlt(2*v, tl, tm, idx, u);
    else dlt(2*v+1, tm+1, tr, idx-t[2*v], u);
     t[v] = t[v*2] + t[v*2+1];
     return;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int in=1;in<=t;in++)
    {
        scanf("%d", &n);
         reset();
        for(int i=1;i<n;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=n;i++) sort(g[i].begin(), g[i].end());
        seq.push_back(0);
        dfs(1, -1);
        for(int i=1;i<=n;i++)
        {
            update(1, 1, n, i, 1);
        }
        tot=n;
        printf("Case %d:\n", in);
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int tp;
            scanf("%d", &tp);
            if(tp==1)
            {
                int u, x;
                scanf("%d%d", &u, &x);
                if(tot<=0) continue;
                int sm=st[u]-1;
                int y=sum(1, 1, n, 1, sm);
                int z=sum(1, 1, n, st[u], ed[u]);
                z=min(x, z);
                while(z--)
                {
                    dlt(1, 1, n, y+1, u);
                }
            }
            if(tp==2)
            {
                int u;
                scanf("%d", &u);
                printf("%d\n", !ar[ed[u]]);
            }
        }
    }
    return 0;
}
