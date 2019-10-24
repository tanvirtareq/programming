#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{

#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int ans=0;
        int tot=0;
        int n;
        cin>>n;
        int ar[n+10][n+10];
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
            {
                cin>>ar[j][k];

                tot+=ar[j][k];
            }


        for(int j=1; j<=n; j++)
            for(int k=j; k<=n; k++)
            {
                if(j==k && ar[j][k]>0)
                {
                    ans+=ar[j][k];
                    ar[j][k]=0;

                }
                else if(ar[j][k]>0 && ar[k][j]>0)
                {
                    ans+=max(ar[j][k], ar[k][j]);
                    ar[k][j]=ar[j][k]=min(ar[j][k], ar[k][j]);
                }
                else
                {
                    (ar[j][k]>0)? ar[k][j]=ar[j][k]: ar[j][k]=ar[k][j];
                }

            }

        // for(int j=1;j<=n;j++){
        //     for(int k=1;k<=n;k++)
        //         cout<<ar[j][k]<<"  ";
        //         cout<<endl;
        // }

        vi v[n+10];

        for(int k=1;k<=n;k++)
        {
            for(int j=k;j<=n;j++)
            {
                if(ar[k][j]>0)
                {
                    v[k].push_back(j);
                    v[j].push_back(k);
                }
            }
        }

        int vis[n+10]={0};

        int ct=0;

        queue<int> q;

        q.push(1);

        vis[1]=1;
        ct++;

        while(!q.empty())
        {
            int x=q.front();
            q.pop();

            for(int j=0;j<v[x].size();j++)
            {
                if(vis[v[x][j]]==0) vis[v[x][j]]=1, ct++, q.push(v[x][j]);
            }
        }

        if(ct<n)
        {
            cout<<"Case "<<i<<": "<<-1<<endl;
            continue;
        }

        memset(vis, 0, sizeof vis);

        vis[1]=1;

        priority_queue<ii, vector<ii>, greater<ii> > pq;

        for(int j=0;j<v[1].size();j++)
        {
            pq.push(make_pair(ar[1][v[1][j]], v[1][j]));
        }

        int ev=0;

        while(!pq.empty())
        {
            ii pr=pq.top();
            pq.pop();

            int x=pr.second;
            int cst=pr.first;

            if(vis[x]==1) continue;

            vis[x]=1;

            ev+=cst;

            for(int j=0;j<v[x].size();j++)
            {
                pq.push(make_pair(ar[x][v[x][j]], v[x][j]));
            }

        }

        cout<<"Case "<<i<<": "<<tot-ev<<endl;

       
    }

    return 0;
}


/**

3



2

27 26

1 52



4

0 10 10 0

0 0 1 1

0 0 0 2

0 0 0 0



4

0 1 0 0

1 0 0 0

0 0 0 1

0 0 1 0
*/
