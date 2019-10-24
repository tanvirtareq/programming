#include<bits/stdc++.h>

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> v[n+10];

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);

    }

    int k=ceil((double)(m+n)/2.0);

    int d[n+10];

    for(int i=1;i<=n;++i)
    {
        d[i]=v[i].size();

    }

    int r=m-k;
    bool vis[n+10]={0};
    queue<int> q;

    while(r>0)
    {


    cout<<m<<endl;

    int vis2[n+10][n+10];
    memset(vis2, 0, sizeof vis2);

    for(int i=1;i<=n;i++)


      for(int i=1;i<=n;i++)
    {

        for(int j=0;j<v[i].size();++j)
        {
            if(vis2[i][v[i][j]]==0 and vis2[v[i][j]][i]==0)
            {
                cout<<i<<" "<<v[i][j]<<endl;
                vis2[i][v[i][j]]=1;
                vis2[v[i][j]][i]=1;
            }

        }

    }

          int rt=q.front();
          q.pop();

          vis[rt]=1;


          for(int i=0;i<v[rt].size();++i)
          {
              if(vis[v[rt][i]]==0)
             q.push(v[rt][i]);

             if(ceil(d[rt]/2.0)<=v[rt].size()-1 and ceil(d[v[rt][i]]/2.0)<=v[v[rt][i]].size()-1)
             {
                 r--;
                 m--;
                 vector<int> :: iterator it;

                 it=v[rt][i];

                 v[rt].erase(i);
                 int tl=v[rt][i];
                 int j=0;
                 for(;j<v[tl].size();j++)
                    {
                        if(v[tl][j]==rt) break;
                    }

                v[tl].erase(j);


             }

          }

      }

    }
}


