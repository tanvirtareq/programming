#include <bits/stdc++.h>
using namespace std;
#define int long long
long long val[200005];

struct node
{
	int dis,num;
	bool operator < (const node &a)const{
		if(dis==a.dis)return num<a.num;
		return dis<a.dis;
	}
	bool operator==(const node & a)const{
		return dis==a.dis && num==a.num;
	}
};
node inf;
set<node> st[200005];

struct query{
	int typ;
	long long x, y;
}que[200005];

int depth[200005];

vector<int> e[200005];
void dfs(int i, int par) {
	if(par != -1) depth[i] = depth[par] + 1;
	for(int j : e[i]) if(j -par) dfs(j, i);
}

node tree[1000050];
inline node min(node a,node b)
{
	if(a<b)return a;return b;
}
void init(int nd, int i,int j)
{
	if(i==j){
		tree[nd]=(*st[i].begin());
		return ;
	}
	int mid=(i+j)>>1;
	init(nd*2,i,mid);
	init(nd*2+1,mid+1,j);
	tree[nd]=min(tree[nd*2],tree[nd*2+1]);
}
void update(int nd, int i,int j,int P,node val){
	if(j<P || i>P)return;
	if(i==j && j==P){
		tree[nd]=val;
		return;
	}
	int mid=(i+j)>>1;
	update(nd*2,i,mid,P,val);
	update(nd*2+1,mid+1,j,P,val);
	tree[nd]=min(tree[nd*2],tree[nd*2+1]);
}

node query(int nd, int i,int j,int l,int r){
	if(j<l || i>r)return inf;
	if(l<=i && j<=r)return tree[nd];
	int mid=(i+j)>>1;
	return min(query(nd*2,i,mid,l,r),query(nd*2+1,mid+1,j,l,r));
}


int32_t main() {
	long long n, t, x, y, q;
	inf={100000000,0};
	for(int i=0;i<200005;i++)st[i].insert(inf);
	// cin >> n;
	scanf("%lld",&n);
	vector<long long> v;
	for(int i=1; i<=n; i++) scanf("%lld",&val[i]), v.push_back(val[i]);

	for(int i=1; i<n; i++) {
		int u,v;
		scanf("%lld %lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,-1);
	// cin>>q;
	scanf("%lld",&q);
	for(int i=1; i<=q; i++) {
		// cin >> t;
		scanf("%lld",&t);
		if(t == 1)
		scanf("%lld %lld",&x,&y); 
			// cin >> x >> y;
		else scanf("%lld",&y), x = -1;

		que[i] = {(int)t, x, y};
		v.push_back(y);
	}

	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));

	int ma=0;
	for(int i=1; i<=n; i++){
		val[i] = lower_bound(v.begin(), v.end(), val[i]) - v.begin() + 1;
		st[val[i]].insert({depth[i],i});
		ma=max(ma,val[i]);
		assert(ma<200002);
	}
	init(1,1,200002);
	for(int i=1; i<=q; i++) {
		que[i].y = lower_bound(v.begin(), v.end(), que[i].y) - v.begin() + 1;
		ma=max(ma,que[i].y);
		assert(ma<200002);
		if(que[i].typ==1)
		{
			int age=val[que[i].x];
			int setval=que[i].y;
			// cout << "###" << endl;
			// for(auto i : st[age]) cout << i.num << ' ' << i.dis << endl;
			// cout << depth[que[i].x] << ' ' << que[i].x << endl;
			if(st[age].find({depth[que[i].x],(int)que[i].x}) != st[age].end())
			st[age].erase(st[age].find({depth[que[i].x],(int)que[i].x}));
			// st[age].erase({depth[que[i].x],(int)que[i].x});
			// cout << endl;
			// for(auto i : st[age]) cout << i.num << ' ' << i.dis << endl;
			// cout << "###" << endl;
			update(1,1,200002,age,*st[age].begin());
			st[setval].insert({depth[que[i].x],(int)que[i].x});
			update(1,1,200002,setval,*st[setval].begin());
			// node tmp=query(1,1,200002,age,age);
			// cout<<"#$ "<<tmp.dis<<' '<<tmp.num<<endl0
		}
		else{
			node an=query(1,1,200002,que[i].y+1,200002);
			if(an==inf)printf("-1\n");
			else
			printf("%lld\n", an.num);
		}
		assert(ma<200002);
	}

}