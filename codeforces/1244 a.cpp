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

		ll a, b, c, d, k;
		cin>>a>>b>>c>>d>>k;
		ll x=a/c+(a%c>0);
		ll y=b/d+(b%d>0);
		if(x+y>k) cout<<-1<<endl;
		else cout<<x<<" "<<y<<endl;
	}

	return 0;
}