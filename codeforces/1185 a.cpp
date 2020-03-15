#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;



int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int d;
	std::vector<int> v;

	f(i, 3)
	{
		int x;
		cin>>x;
		v.pb(x);
	}

	cin>>d;
	sort(v.begin(), v.end());

	int x=0;
	// cout<<v[1]-v[0]<<endl;
	x+=(v[1]-v[0])>=d? 0: d-(v[1]-v[0]);
	x+=(v[2]-v[1])>=d? 0: d-(v[2]-v[1]);
	cout<<x<<endl; 

	return 0;
}

