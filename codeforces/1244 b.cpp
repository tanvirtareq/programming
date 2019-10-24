#include<bits/stdc++.h>
#define ll long long

using namespace std;

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
		string x;
		cin>>n>>x;

		ll mx=0;

		for(int i=0;i<x.size();i++)
		{
			if(x[i]=='1')
			{
				ll f=max(2LL*(i+1), (ll)2*((ll)x.size()-i));
				mx=max(mx, f);
			}
		}
		cout<<max(n, mx)<<endl;
	}

	return 0;
}