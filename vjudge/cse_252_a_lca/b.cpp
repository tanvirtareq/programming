#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define eps 1e-17
#define xd 101000

using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

 vector<int> adj[xd], cst[xd],  tin,tout;
 vector<vector<int> > up, x, mn;
int l, timer, n, m;

 void clr()
 {
 	for(int i=0;i<xd;i++) adj[i].clear(),  cst[i].clear();
 	tin.clear();
 	tout.clear();
 	up.clear();
 	x.clear();
 }

 void dfs(int v, int p, int cs)
 {
 	tin[v]=++timer;
 	up[v][0]=p;
 	x[v][0]=cs;
 	mn[v][0]=cs;

 	for(int i=1;i<=l;i++){
 		x[v][i]=max(x[v][i-1], x[up[v][i-1]][i-1]);
 		mn[v][i]=min(mn[v][i-1], mn[up[v][i-1]][i-1]);
 	 	up[v][i]=up[up[v][i-1]][i-1];
 	}

 	for(int i=0;i<adj[v].size();i++)
 	{
 		int u=adj[v][i];
 		if(u!=p) dfs(u, v, cst[v][i]);

 	}

 	tout[v]=++timer;
 }


 void pre()
 {
 	tin.resize(n+1);
 	tout.resize(n+1);
 	timer=0;
 	up.assign(n+1, vector<int> (l+10));
 	x.assign(n+1, vector<int> (l+10));
 	mn.assign(n+1, vector<int> (l+10));

 	dfs(1, 1, 0);

 }

 bool is_ancestor(int u, int v)
 {
 	return tin[u]<=tin[v] and tout[u]>=tout[v];
 }

 ii fc(int v, int u)
 {
 	int mx=0;
 	int Mn=INT_MAX;
 	for(int i=l;i>=0;i--)
 	{
 		if(!is_ancestor(up[u][i], v))
 		{
 			mx=max(mx, x[u][i]);
 			Mn=min(Mn, mn[u][i]);
 			u=up[u][i];
 		}
 	}

 	return make_pair(min(Mn, mn[u][0]) ,max(mx, x[u][0]));
 }

 ii lca(int u, int v)
 {
 	if(is_ancestor(u, v)) return fc(u, v);
 	if(is_ancestor(v,u)) return fc(v, u);

 	int mx=0;
 	int Mn=INT_MAX;

 	for(int i=l;i>=0;i--)
 		if(!is_ancestor(up[u][i], v)){
 			mx=max(mx, x[u][i]);
 			Mn=min(Mn, mn[u][i]);
 			u=up[u][i];
 		}

 	ii p=fc(up[u][0], v);

 	// return max(max(mx, x[u][0]), );

 	ii p2=make_pair(min(Mn, min(mn[u][0], p.first)) , max(mx, max(x[u][0], p.second)));

 	return p2;
 }

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);
	 for(int in=1;in<=t;in++)
	 {
	 	printf("Case %d:\n", in);
	 	scanf("%d", &n);
	 	m=n-1;
	 	clr();
	 	l=log2(n)+1;

	 	for(int i=1;i<=m;i++)
	 	{
	 		int x, y, c;
	 		scanf("%d%d%d", &x, &y , &c);
	 		adj[x].push_back(y);
	 		adj[y].push_back(x);
	 		cst[x].push_back(c);
	 		cst[y].push_back(c);
	 	}

	 	pre();
	 	int m;
	 	scanf("%d", &m);
	 	while(m--)
	 	{
	 		int x,y;
	 		scanf("%d%d", &x, &y);
	 		ii p=lca(x, y);
	 		printf("%d %d\n", p.first, p.second);
	 	}
	 }
	return 0;
}
