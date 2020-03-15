#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
	ll n;
	cin>>n;
	ll ar[2*n+10];
	for(ll i=0;i<2*n;i++)
	{
		cin>>ar[i];
	}
	sort(ar, ar+2*n);

	ll mx=-9000000000;
	ll mn=-mx;

	for(ll i=0;i<n;i++)
	{
		ll y=ar[i]+ar[2*n-i-1];
		// cout<<y<<endl;
		mx=max(y, mx);
		mn=min(y, mn);

	}
	cout<<mx-mn<<endl;

	return 0;
}