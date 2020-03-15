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

int T, n, e;

int v[110][110];
int par[110];

int vis[55];
int s, t;

int dfs(int rt, int *flw)
{
//    cout<<rt<<endl;
    vis[rt]=1;
    if(rt==t)
    {
        return 1;
    }

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

bool bfs(int rt, int *flw)
{
    vis[rt]=1;

    queue<int> q;
    q.push(rt);

    while(!q.empty())
    {
        rt=q.front();
        q.pop();
//        cout<<rt<<endl;
        for(int i=1;i<=n;i++)
        {
            if(v[rt][i]>0 and vis[i]==0)
            {
                vis[i]=1;
                *flw=min(*flw, v[rt][i]);
                par[i]=rt;
                q.push(i);
                if(i==n) return true;
            }

        }

    }
    return false;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i=1;i<=T;i++)
    {
        memset(v, 0, sizeof v);
        memset(vis, 0, sizeof vis);

        cin>>n;
        cin>>s>>t>>e;

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
        while(bfs(s, &flw))
        {
//            cout<<flw<<endl;
            if(flw==0) break;

            mxfl+=flw;

            int x=par[n];
            int y=n;
            while(x!=1)
            {
                v[x][y]-=flw;
                v[y][x]+=flw;
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
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20

*/


