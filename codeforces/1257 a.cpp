#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define xd 101000

using namespace std;
typedef long long ll;

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		int n, x, a, b;
		cin>>n>>x>>a>>b;

		int r1=min(a,b);
		int r2=max(a,b);

		int d=r2-r1;
		// dbg(d);

		d+=min(x, r1-1);
		// dbg(d);
		x-=min(x, r1-1);
		// dbg(x);
		d+=min(x, n-r2);
		cout<<d<<endl;
	}
	
	return 0;
}
