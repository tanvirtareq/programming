#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair


using namespace std;

typedef long long ll;
typedef long long unsigned lu;

vector<ll> adj[100010];
ll  tedg[100010], n,m, q, x, y;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n>>m;

	for(ll  i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(x>y) swap(x, y);
		adj[x].push_back(y);
		tedg[x]++;
		tedg[y]++;
	}

	ll  ans=0;

	for(ll  i=1;i<=n;i++)
	{
		ll  outdg=adj[i].size();
		ll  indg=tedg[i]-outdg;
		ans+=outdg*indg;
	}
	cout<<ans<<endl;
	cin>>q;
	while(q--)
	{
		cin>>x;

		ll  outdgx=adj[x].size();
		ll  indgx=tedg[x]-outdgx;

		ans-=outdgx*indgx;

		while(adj[x].size()>0)
		{
			y=adj[x].back();
			adj[x].pop_back();
			ll  outdgy=adj[y].size();
			ll  indgy=tedg[y]-outdgy;
			ans-=outdgy*indgy;

			adj[y].push_back(x);

			outdgy=adj[y].size();
			indgy=tedg[y]-outdgy;
			ans+=outdgy*indgy;
		}

		outdgx=adj[x].size();
		indgx=tedg[x]-outdgx;

		ans+=outdgx*indgx;

		cout<<ans<<endl;
	}

	return 0;
}