#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

int ck(ll x)
{
	int vis[20];

	memset(vis, 0, sizeof vis);

	while(x)
	{
		if(vis[x%10]==1) return 0;

		vis[x%10]=1;
		x=x/10;
	}

	return 1;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll l, r, x;
	cin>>l>>r;

	for(x=l;x<=r;x++)
	{
		if(ck(x))
		{
			cout<<x<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

	return 0;
}