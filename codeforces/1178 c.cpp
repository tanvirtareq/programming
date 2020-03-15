#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define v(a) vector<a>
#define p(a, b) pair<a,b> 
#define md 998244353

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pqi;
typedef priority_queue<ll , vi, greater<ll> > mnpqi;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll w, h;
	cin>>w>>h;

	ll ans=4;

	for(int i=2;i<=w;i++)
	{
		ans=(ans*2)%md;
	}
	for(int i=2;i<=h;i++)
	{
		ans=(ans*2)%md;
	}

	cout<<ans<<endl;

	return 0;
}