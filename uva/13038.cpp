#include<bits/stdc++.h>

using namespace std;

 vector<int> v[110000];

 int vis[110000];

int dfs(int rt, int t)
{
//    cout<<rt<<" "<<t<<endl;
    int mx=t;

    for(int i=0;i<v[rt].size();i++)
    {
        int x=v[rt][i];
        mx=max(mx, dfs(v[rt][i], t+1));

    }
    return mx;
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
    for(int in=1;in<=t;in++)
    {
       int n, m;
       cin>>n>>m;
       int ar[110000];
       memset(ar, 0, sizeof ar);
       memset(vis, 0, sizeof vis);

       for(int i=0;i<=n;i++) v[i].clear();

       for(int i=1;i<=m;i++)
       {

           int x, y;
           cin>>x>>y;
           v[x].push_back(y);
           ar[y]=1;
       }

       vector<int> vc;

       for(int i=1;i<=n;i++)
       {

           if(ar[i]==0) vc.push_back(i);
       }

       int mx=0;

       for(int i=0;i<vc.size();i++)
       {

           int rt=vc[i];
           mx=max(mx, dfs(rt, 1));
       }

       cout<<"Case "<<in<<": "<<mx<<endl;

       
    }
    return 0;
}


/**
3
4  21  23  44  31  22  34  17  33  63  71  5

*/