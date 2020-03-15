#include<bits/stdc++.h>

using namespace std;

int bfs(int s, int t,int n,  int mat[][110], int par[])
{
    bool vis[110];
    memset(vis, 0, sizeof vis);

    vis[s]=1;

    queue<int> q;
    q.push(s);
    par[s]=-1;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=1;

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 and mat[x][i]!=0)
            {
                par[i]=x;
                q.push(i);
                if(i==t) return 1;

            }

        }

    }

    return 0;

}

int maxflow(int s, int t,int n, int mat[][110])
{
    int par[110];
    int x=bfs(s, t,n, mat, par);

//    cout<<x<<endl;

    if(x==0)
    {
        return 0;
    }

    int max_flow=0, min_cap=INT_MAX;

    int i=t;

    while(i!=s)
    {
        min_cap=min(min_cap, mat[par[i]][i]);
        i=par[i];
    }
//    cout<<i<<endl;

    i=t;

    while(i!=s)
    {
        mat[par[i]][i]-=min_cap;

        mat[i][par[i]]+=min_cap;
        i=par[i];
    }
//    cout<<i<<endl;
    return min_cap+maxflow(s, t,n, mat);





}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int s, t, c;
        cin>>s>>t>>c;

        int mat[110][110];

        memset(mat, 0, sizeof mat);
        for(int j=1;j<=c;j++)
        {
            int a, b, w;
            cin>>a>>b>>w;
            mat[a][b]+=w;
            mat[b][a]+=w;

        }

        cout<<"Case "<<i<<": "<<maxflow(s, t,n, mat)<<endl;


    }

    return 0;
}
