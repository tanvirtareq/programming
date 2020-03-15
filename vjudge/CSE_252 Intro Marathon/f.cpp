#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof a)
#define pb(a) push_back(a)

#define f(i, b, n) for(ll i=b;i<=n;i++)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;

	for(int i=1;i<=t;i++)
	{
		int n, q;
		cin>>n>>q;

		vi v;

		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}

		cout<<"Case "<<i<<":"<<endl;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='c')
			{
				int x;
				cin>>x;
				if(x-1>=v.size())
				{
					cout<<"none"<<endl;
					continue;
				}
				cout<<v[x-1]<<endl;
				v.erase(v.begin()+x-1);
			}
			else
			{
				int x;
				cin>>x;
				v.pb(x);
			}
		}
	}

	return 0;
}