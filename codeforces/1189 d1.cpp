#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin>>n;

	vector<int> v[n+10];

	f(i, n-1)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].pb(a);

	}
	int fl=0;

	f(i, n)
	{
		if(v[i].size()==2)
		{
			fl=1;
			// cout<<i<<endl;
			// cout<<v[i][0]<<endl;
			// cout<<v[i][1]<<endl;
			break;
		}
	}

	fl?cout<<"NO"<<endl:cout<<"YES"<<endl;

	
	return 0;
}