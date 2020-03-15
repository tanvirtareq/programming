#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" ="<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		ll s=0;
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			s+=x;
		}

		ll ans=s/n;
		if(s%n) ans++;

		cout<<ans<<endl;
	}

	return 0;
}