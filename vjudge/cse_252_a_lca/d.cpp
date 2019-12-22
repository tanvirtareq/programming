#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define xd 101000

using namespace std;
typedef long long ll;

vector<ll> tin, tout, adj[xd], cst[xd];
vector<vector<ll> > up, dst;
ll l, n, timer;

void dfs(ll v,ll p, ll c)
{
	tin[v]=++timer;
	up[v][0]=p;
	dst[v][0]=c;
	for(ll i=1;i<=l;i++)
	{
		up[v][i]=up[up[v][i-1]][i-1];
		dst[v][i]=dst[v][i-1]+dst[up[v][i-1]][i-1];		
	}
	for(ll i=0;i<adj[v].size();i++)
		if(p!=adj[v][i]) dfs(adj[v][i], v, cst[v][i]);
	tout[v]=++timer;
}
void pre()
{
	tin.resize(n+1);
	tout.resize(n+1);
	timer=0;
	up.assign(n+1, vector<ll> (l+5));
	dst.assign(n+1, vector<ll> (l+5));
	dfs(0, 0, 0);
}
bool is_ancestor(ll u, ll v)
{
	return tin[u]<=tin[v] and tout[u]>=tout[v];
}
ll fc(ll v, ll u)
{
	ll d=0;
	for(ll i=l;i>=0;i--)
	{
		if(!is_ancestor(up[u][i], v))
		{
			d+=dst[u][i];
			u=up[u][i];
		}
	}
	return d+dst[u][0];
}
ll csd(ll u, ll v)
{

	if(is_ancestor(u, v)) return fc(u, v);
	if(is_ancestor(v, u)) return fc(v, u);

	ll d=0;

	for(ll i=l;i>=0;i--)
	{
		if(!is_ancestor(up[u][i], v)){
			d+=dst[u][i];
			u=up[u][i];
		}
	}

	return d+dst[u][0]+fc(up[u][0], v);
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%lld", &n);
	l=log2(n)+10;

	for(ll i=1;i<n;i++)
	{
		ll x, y, c;
		scanf("%lld%lld%lld", &x, &y, &c);
		adj[x].push_back(y);
		adj[y].push_back(x);
		cst[x].push_back(c);
		cst[y].push_back(c);
	}

	pre();

	ll m;
	scanf("%lld", &m);
	// dbg(m);

	while(m--)
	{
		ll x, y;
		
		scanf("%lld%lld\n", &x, &y);
		// dbg(x);
		// dbg(y);
		printf("%lld\n", csd(x, y));
	}


	
	return 0;
}
