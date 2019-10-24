#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;


int t, n, e;
int mc[55];

int v[55][55];
int par[55];

int vis[55];

int dfs(int rt, int *flw)
{
//    cout<<rt<<endl;
    vis[rt]=1;
    if(rt==n)
    {
        return 1;
    }
    if(rt!=1)
    *flw=min(*flw, mc[rt]);

    if(*flw==0) return 0;

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0 and  v[rt][i]>0)
        {
            *flw=min(*flw, v[rt][i]);
//            cout<<"flow= "<<flw<<endl;

            if(dfs(i, flw))
            {
                par[i]=rt;
                return 1;
            }

        }

    }

    return 0;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(v, 0, sizeof v);
        memset(mc, 0, sizeof mc);
        memset(vis, 0, sizeof vis);

        cin>>n>>e;
        for(int j=2;j<n;j++)
        {
            cin>>mc[j];

        }

        while(e--)
        {
            int x, y, w;
            cin>>x>>y>>w;
            v[x][y]+=w;
            v[y][x]+=w;

        }

        int mxfl=0;
        int flw=INT_MAX;

//        cout<<"yes"<<endl;
        while(dfs(1, &flw))
        {
//            cout<<flw<<endl;
//            if(flw==0) break;

            mxfl+=flw;

            int x=par[n];
            int y=n;
            while(x!=1)
            {
                v[x][y]-=flw;
                v[y][x]+=flw;
                mc[x]-=flw;
                y=x;
                x=par[x];

            }
            if(x==1)
            {
                v[x][y]-=flw;
                v[y][x]+=flw;

            }

            flw=INT_MAX;

//            cout<<mxfl<<endl<<endl;
            memset(par, 0, sizeof par);
            memset(vis, 0, sizeof vis);

        }

        cout<<"Case "<<i<<": "<<mxfl<<endl;

    }


	return 0;
}

/**

2
4 4
2 5
1 2 3
1 3 3
2 4 1
3 4 3
4 4
2 2
1 2 3
1 3 3
2 4 1
3 4 3

*/

