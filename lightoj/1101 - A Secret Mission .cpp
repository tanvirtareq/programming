#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define eps 1e-17
#define xd 100000

using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

 vector<int> adj[xd], cst1[xd],cst[xd], mst[xd], tin,tout;
 vector<vector<int> > up, x;
int l, timer, n, m;

 void clr()
 {
 	for(int i=0;i<xd;i++) adj[i].clear(), cst1[i].clear(), cst[i].clear(), mst[i].clear();
 	tin.clear();
 	tout.clear();
 	up.clear();
 	x.clear();
 }


 void Mst()
 {

 	priority_queue<iii, vector<iii> , greater<iii> > pq;

 	for(int i=0;i<adj[1].size();i++)
 	{
 		pq.push(make_pair(cst1[1][i], make_pair(1, adj[1][i])));
 	}
 	int vis[xd]={0};
 	vis[1]=1;

 	while(!pq.empty())
 	{
 		iii p=pq.top();
 		pq.pop();
 		int cs=p.first;
 		int u=p.second.first;
 		int v=p.second.second;

 		if(vis[u] and vis[v]) continue;

 		if(vis[u]==1) swap(u, v);

 		mst[u].push_back(v);
 		mst[v].push_back(u);
 		cst[u].push_back(cs);
 		cst[v].push_back(cs);
 		vis[u]=1;

 		for(int i=0;i<adj[u].size();i++)
 		{
 			if(vis[adj[u][i]]) continue;
 			pq.push(make_pair(cst1[u][i], make_pair(u, adj[u][i])));
 		}

 	}
 }

 void dfs(int v, int p, int cs)
 {
//     cout<<v<<" "<<p<<" "<<cs<<endl;
 	tin[v]=++timer;
// 	cout<<"yes"<<endl;
 	up[v][0]=p;
 	x[v][0]=cs;
// 	dbg(l);

 	for(int i=1;i<=l;i++){
 		x[v][i]=max(x[v][i-1], x[up[v][i-1]][i-1]);
 	 	up[v][i]=up[up[v][i-1]][i-1];
 	}
// 	cout<<"Yes"<<endl;

 	for(int i=0;i<mst[v].size();i++)
 	{
 		int u=mst[v][i];
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

// 	cout<<"yes"<<endl;
 	dfs(1, 1, 0);
// 	cout<<"yes"<<endl;

 }

 bool is_ancestor(int u, int v)
 {
 	return tin[u]<=tin[v] and tout[u]>=tout[v];
 }

 int fc(int v, int u)
 {
 	int mx=0;
 	for(int i=l;i>=0;i--)
 	{
 		if(!is_ancestor(up[u][i], v))
 		{
 			mx=max(mx, x[u][i]);
 			u=up[u][i];
 		}
 	}

 	return max(mx, x[u][0]);
 }

 int lca(int u, int v)
 {
 	if(is_ancestor(u, v)) return fc(u, v);
 	if(is_ancestor(v,u)) return fc(v, u);

 	int mx=0;

 	for(int i=l;i>=0;i--)
 		if(!is_ancestor(up[u][i], v)){
 			mx=max(mx, x[u][i]);
 			u=up[u][i];
 		}

 	return max(max(mx, x[u][0]), fc(up[u][0], v));

 }

int main()
{
//cout<<"yes"<<endl;

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
//
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif

	int t;
	scanf("%d", &t);
//	cout<<t<<endl;
//	dbg(t);
	 for(int in=1;in<=t;in++)
	 {
	 	printf("Case %d:\n", in);
	 	scanf("%d %d", &n, &m);
	 	clr();
//	 	dbg(m);
	 	l=log2(n)+1;

	 	for(int i=1;i<=m;i++)
	 	{
	 		int x, y, c;
	 		scanf("%d%d%d", &x, &y , &c);
	 		adj[x].push_back(y);
	 		adj[y].push_back(x);
	 		cst1[x].push_back(c);
	 		cst1[y].push_back(c);
	 	}
	 	Mst();
//	 	for(int i=1;i<=n;i++)
//        {
//            cout<<mst[i].size()<<endl;
//            for(int j=0;j<mst[i].size();j++) cout<<mst[i][j]<<" ";
//
//            cout<<endl<<endl;
//
//        }
	 	pre();
	 	int m;
	 	scanf("%d", &m);
//	 	dbg(m);
	 	while(m--)
	 	{
	 		int x,y;
	 		scanf("%d%d", &x, &y);
	 		printf("%d\n", lca(x, y));
	 	}
	 }
	return 0;
}
