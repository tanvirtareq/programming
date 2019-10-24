#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof a)
#define pb(a) push_back(a)

#define f(i, b, n) for(ll i=b;i<=n;i++)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t;
	// cin>>t;
	scanf("%d", &t);

	for(int i=1;i<=t;i++)
	{
		int n, q;
		// cin>>n>>q;
		scanf("%d%d", &n, &q);
		vi v;
		for(int j=1;j<=n;j++)
		{
			int x;
			// cin>>x;
			scanf("%d", &x);
			v.pb(x);
		}
		// cout<<"Case "<<i<<":"<<endl;
		printf("Case %d:\n", i);
		while(q--)
		{
			int a, b;
			// cin>>a>>b;
			scanf("%d%d", &a, &b);
			vi::iterator it1, it2;
			it1=lower_bound(v.begin(), v.end(), a);
			it2=upper_bound(v.begin(), v.end(), b);
			int d= distance(it1, it2);
			// cout<<d<<endl;
			printf("%d\n", d);
		}

	}

	return 0;
}