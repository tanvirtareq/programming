#include<bits/stdc++.h>

// #define mx  30000
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mk make_pair
#define f(i, a, b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int  gp[1000][1000];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int vis[1000];
int N, m, n;

int dfs(int src, int tg, int par[])
{

    // cout<<src<<" "<<tg<<endl;

    if(src==tg) { return 1;}

    vis[src]=1;

    for(int i=0;i<=tg;i++)
    {
        if(vis[i]==0 and gp[src][i]>0)
        {
            par[i]=src;
            if(dfs(i, tg, par)) return 1;
        }
    }

    return 0;
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


        cin>>m>>n;

        vi v;
        v.pb(0);
        v.pb(0);

        for(int j=1;j<=m;j++)
        {
            char ch, tp;
            int x;
            cin>>ch>>tp>>x;
            v.pb(x);
            if(ch=='B') v.pb(x);
        }
        v.pb(n);
        v.pb(n);

        int mx=0;

        for(int j=2;j<v.size();j+=2)
        {
            mx=max(mx, v[j]-v[j-2]);
        }

        for(int j=3;j<v.size();j+=2)
        {
            mx=max(mx, v[j]-v[j-2]);
        }

        cout<<"Case "<<i<<": ";
        cout<<mx<<endl;
    }

    return 0;
}

///  1 1 5 -5 10 2 4



