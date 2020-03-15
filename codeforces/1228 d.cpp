#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" ="<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

int cl[100010], n, m;
vector<int>adj[100010];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int vis[100010]={0};
	int c[4]={0};

	for(int i=1;i<=n;i++)
		if(adj[i].size()<2)
		{
			// dbg(n);
			cout<<-1<<endl;
			return 0;
		}

	for(int i=0;i<adj[1].size();i++)
	{
		vis[adj[1][i]]=1;
	}

	for(int i=1;i<=n;i++)
		if(vis[i]==0) {

			for(int j=0;j<adj[i].size();j++)
			{
				if(cl[adj[i][j]]==1)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			cl[i]=1;
			c[1]++;
			// dbg(i);
		}


	memset(vis, 0, sizeof vis);

	int rt=adj[1][0];

	for(int i=0;i<adj[rt].size();i++)
		vis[adj[rt][i]]=1;

	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0 and cl[i]!=0)
		{
			cout<<-1<<endl;
			return 0;
		}

		if(vis[i]==0 and cl[i]==0)
		{

			for(int j=0;j<adj[i].size();j++)
			{
				if(cl[adj[i][j]]==2)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			cl[i]=2;
			c[2]++;
		}
	}

	memset(vis, 0, sizeof vis);

	int rt1, f=0;

	for(int i=0;i<adj[rt].size();i++)
	{
		if(cl[adj[rt][i]]==0)
		{
			rt1=adj[rt][i];
			f=1;
			break;
		}
	}

	if(f==0)
	{
		cout<<-1<<endl;
		return 0;
	}

	for(int i=0;i<adj[rt1].size();i++)
	{
		vis[adj[rt1][i]]=1;
	}

	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0 and cl[i]!=0)
		{
			cout<<-1<<endl;
			return 0;
		}

		if(vis[i]==0 and cl[i]==0)
		{
			for(int j=0;j<adj[i].size();j++)
			{
				if(cl[adj[i][j]]==3)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			cl[i]=3;
			c[3]++;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(cl[i]==0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()!=(n-c[cl[i]]))
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	for(int i=1;i<=n;i++) cout<<cl[i]<<" ";


	return 0;
}