#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(ll i=a;i<=b;i++)
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<pair<int,  int> > v;
int n, dp[200000], rl;

#define linear(i, j, k) ((((v[j].first-v[i].first)*(v[k].second-v[i].second)-(v[k].first-v[i].first)*(v[j].second-v[i].second))==0)?1:0)

int rc(int msk)
{
	if(dp[msk]!=-1) return dp[msk];
	int ct=0;
	for(int i=0;i<n;i++) if((msk&(1<<i))==0) ct++;
	if(ct==1) return 1;
	if(ct==0) return 0;
	int mn=INT_MAX;
	int tmp=msk;

	for(int i=0;i<n;i++)
	{
		if((msk&(1<<i))) continue;
		for(int j=i+1;j<n;j++)
		{
			tmp=msk;
			if((tmp&(1<<j))) continue;
			tmp=tmp|(1<<i);
			tmp=tmp|(1<<j);
			for(int k=0;k<n;k++)
				if(linear(i,  j, k)) tmp=tmp|(1<<k);

			mn=min(mn, 1+rc(tmp));
		}
		break;
	}

	return dp[msk]=mn;

}


int main()
{

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);
	f(in,1, t)
	{
		v.clear();
		printf("Case %d: ", in);
		scanf("%d", &n);
		int msk=(1<<(n+1))-1;
		rl=msk;
		for(int i=0;i<n;i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.pb(mk(x, y));
			msk=msk^(1<<i);
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", rc(msk));
	}
	return 0;
}