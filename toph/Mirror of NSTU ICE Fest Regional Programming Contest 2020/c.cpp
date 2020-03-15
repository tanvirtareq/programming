#include<bits/stdc++.h>

#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl
#define MX 100100

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

int mintree[4*MX];

void minupdate(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        mintree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            minupdate(2*node, start, mid, idx, val);
        }
        else
        {
            minupdate(2*node+1, mid+1, end, idx, val);
        }
        mintree[node] = min(mintree[2*node] , mintree[2*node+1]);
    }
}

int minquery(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return INT_MAX;
    }
    if(l <= start and end <= r)
    {
        return mintree[node];
    }
    int mid = (start + end) / 2;
    int p1 = minquery(2*node, start, mid, l, r);
    int p2 = minquery(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}

int chk(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        minupdate(1, 0, v.size()-1, i, v[i]);
    }
    int vis[MX];
    memset(vis, -1, sizeof vis);

    for(int i=0;i<v.size();i++)
    {
        if(vis[v[i]]!=-1)
        {
            int x=minquery(1, 0, v.size()-1, vis[v[i]], i);
            if(x<v[i]) return 1;
        }
        else
        {
            vis[v[i]]=i;
        }
    }
    return 0;
}

int t[4*MX];

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] = add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return max(t[v], get(v*2, tl, tm, pos));
    else
        return max(t[v] , get(v*2+1, tm+1, tr, pos));
}

void solve(int ar[], int n, int q, vector<int> &v)
{
    int ls[MX], rs[MX];
    memset(ls, 0, sizeof ls);
    memset(rs, 0, sizeof rs);
    memset(t, 0, sizeof t);

    for(int i=1;i<=n;i++)
    {
        if(ls[ar[i]]==0) ls[ar[i]]=i;
    }

    for(int i=n;i>=1;i--)
    {
        if(rs[ar[i]]==0) rs[ar[i]]=i;

    }

    update(1, 1, n, 1, n, 1);

    for(int i=2;i<=q;i++)
    {
        if(ls[i]==0 and rs[i]==0)
        {
            if(i==q)
            update(1, 1, n, v[v.size()-1],v[v.size()-1], i);
        }
        else
        {
            update(1, 1, n, ls[i], rs[i], i);
        }
    }

    for(int i=1;i<=n;i++)
    {
        int x=get(1, 1, n, i);
        printf("%d ", x);
    }
    printf("\n");
    return;

}

int main()
{

    int t;
    scanf("%d", &t);

    for(int in=1;in<=t;in++)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        int ar[n+10];
        vector<int>v, vr;
        int prv=0;
        int tmx=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d", &x);
            ar[i]=x;
            tmx=max(tmx, x);
            if(x==0) v.push_back(i);
            else if(x!=0 and x!=prv) vr.push_back(x);

            prv=x;
        }
        if(tmx>q)
        {
             printf("Case %d: NO\n", in);
            continue;
        }
//        cout<<vr.size()<<endl;
        if(chk(vr))
        {
            printf("Case %d: NO\n", in);
        }
        else
        {
            if(v.size()==0)
            {
                int f=0;
                for(int i=1;i<=n;i++)
                {
                    if(ar[i]==q)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    printf("Case %d: NO\n", in);
                    continue;
                }
            }
            printf("Case %d: YES\n", in);
            if(v.size()==0)
            {
                for(int i=1;i<=n;i++) printf("%d ", ar[i]);
                printf("\n");
            }
            else
            solve(ar, n, q, v);
        }
    }

	return 0;
}

/**

4
5 3
2 0 1 3 3
3 4
0 0 0
4 6
5 5 5 5
4 3
2 1 0 2

1
3 1
1 2 0

*/




