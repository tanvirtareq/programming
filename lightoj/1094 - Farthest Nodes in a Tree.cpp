#include<bits/stdc++.h>

#define mx  30000
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int d[mx+10];
 
 int vis[mx+10];
  int n=10;

 void dfs(int rt, int cs, std::vector<ii> v[])
 {
    // cout<<cs<<endl;
    vis[rt]=1;
    d[rt]=cs;

    for(int i=0;i<v[rt].size();i++)
    {
        int nxt=v[rt][i].first;
        int c=v[rt][i].second;
        if(vis[nxt]==0) dfs(nxt, cs+c, v);
    }
    return;

 }

 int fnd()
 {
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(d[x]<d[i]) x=i;
        // cout<<d[i]<<endl;
    }
    // cout<<d[x]<<endl;
    return x;
 }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
    // cout<<t<<endl;
    for(int i=1;i<=t;i++)
    {

       cin>>n;

       std::vector<ii> v[n+10];

        for(int j=1;j<n;j++)
        {
            int x, y, w;
            cin>>x>>y>>w;
            v[x].push_back(make_pair(y, w));
            v[y].pb(mk(x, w));
            
        }
        // cout<<"yt"<<endl;
        clr(vis);

        dfs(0, 0, v);

        int x=fnd();
        // cout<<x<<endl;

        clr(vis);

        dfs(x, 0, v);

        x=fnd();


   
        cout<<"Case "<<i<<": ";
        cout<<d[x]<<endl;

        for(int j=0;j<=n+10;j++)
        {
            v[j].clear();
        }
        // cout<<"as"<<endl;
    }

    // cout<<"df"<<endl;

    // return 0;
}

///  1 1 5 -5 10 2 4



