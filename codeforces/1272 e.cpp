#include<bits/stdc++.h>
using namespace std;
int n, tmp, odd[300000], even[300000], vis[300000], ar[300000], in[300000];
vector<int> adj[300000];
int fc=1000000;
void bfs(int rt)
{
    queue<int> q;
    q.push(rt);
    while(!q.empty())
    {
        int r=q.front();
        q.pop();
        for(int i=0;i<adj[r].size();i++)
        {
            if(odd[adj[r][i]]>odd[r]+1 or even[adj[r][i]]>even[r]+1)
            {
                odd[adj[r][i]]=min(odd[adj[r][i]], 1+odd[r]);
                even[adj[r][i]]=min(even[adj[r][i]], 1+even[r]);
                q.push(adj[r][i]);
            }
        }
    }
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        ar[i]=tmp;
        if(ar[i]%2==0) odd[i]=fc, even[i]=0;
        else odd[i]=0, even[i]=fc;
        if(i-tmp>0) adj[i-tmp].push_back(i);
        if(i+tmp<=n) adj[i+tmp].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(vis[i]==0) bfs(i);
    for(int i=1;i<=n;i++)
        if(vis[i]==1)  bfs(i);
    for(int i=1;i<=n;i++)
    {
        if(ar[i]%2==0) (odd[i]==fc)? cout<<-1<<" " : cout<<odd[i]<<" ";
        else (even[i]==fc)? cout<<-1<<" " : cout<<even[i]<<" ";
    }
}
