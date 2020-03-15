#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100100];

int c[3][100100], vis[100010];

int rc(int st, int cl, string x)
{
	// cout<<endl<<endl;
	// cout<<st<<" "<<cl<<endl;
	// cout<<adj[st][0]<<endl;
	// cout<<vis[2]<<endl;
	if(adj[st].size()==1 and vis[adj[st][0]]!=-1) return c[x[cl]-'0'][st];

	for(int i=0;i<adj[st].size();i++)
	{
		// cout<<adj[st][i]<<" ";
		if(vis[adj[st][i]]==-1)
		{
			vis[adj[st][i]]=cl;
		 return c[x[cl]-'0'][st]+rc(adj[st][i], (cl+1)%3, x);
		}
	}

	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;


	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++) cin>>c[i][j];

	for(int i=1;i<n;i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int rt=-1;

	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()>2) return cout<<-1<<endl, 0;

		if (adj[i].size()==1) rt=i;

	}

	int mx[6];
	mx[0]=INT_MAX;
	int mxx=0;

	string x="012";
	// cout<<rt<<endl;

	for(int i=1;i<=6;i++)
	{
		memset(vis, -1, sizeof vis);
		vis[rt]=0;
		mx[i]=rc(rt, 1, x);
		if(mx[i]<mx[mxx]) mxx=i;

		// cout<<x<<" "<<mx[i]<<endl;
		next_permutation(x.begin(), x.end());
	}

	x="012";

	for(int i=1;i<mxx;i++) next_permutation(x.begin(), x.end());

	memset(vis, -1, sizeof vis);
	vis[rt]=0;
	// cout<<x<<endl;
	
	rc(rt, 1, x);

	cout<<mx[mxx]<<endl;
	for(int i=1;i<=n;i++) cout<<x[vis[i]]<<" ";
	
}