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

vector<int> v;
int n,  k,  w, dp[110][110];
int rc(int i, int j)
{
	if(i>=v.size() || j>=k) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up=(upper_bound(v.begin(), v.end(), v[i]+w)-v.begin());
	return dp[i][j]=max(up-i+rc(up, j+1), rc(i+1, j));
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
		scanf("%d%d%d", &n, &w, &k);
		for(int i=1;i<=n;i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.pb(y);
		}
		memset(dp, -1, sizeof dp);
		sort(v.begin(), v.end());
		printf("%d\n", rc(0, 0));
	}
	return 0;
}