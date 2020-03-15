#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll ct(ll x, ll k)
{
	ll ret=0;
	ll j=0;
	while(x)
	{
		if(x%k) ret|=(1LL<<j);
		j++;
		x=x/k;
	}
	return ret;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		vector<ll> v;
		ll all=0;
		int f1=0;
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			if(f1==1) continue;
			ll y=ct(x, k);
			if((all^y)!=(all|y)) f1=1;
			all=all|y;
		}
		
		if(f1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

	return 0;

}
