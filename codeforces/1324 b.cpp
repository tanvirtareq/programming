#include<bits/stdc++.h>
#define ll long long

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 


int main()
{

	ll n;
	cin>>n;

	ll ar[n+10], br[n+10], cr[n+10];
	for(ll i=1;i<=n;i++) cin>>ar[i];
	for(ll i=1;i<=n;i++) cin>>br[i];

	vector<int> v;

	for(ll i=1;i<=n;i++) v.push_back(ar[i]-br[i]);

	sort(v.begin(), v.end());

	// ordered_set s;
	// s.insert(cr[1]);

	ll ct=0;

	for(ll i=0;i<n;i++)
	{
		auto it=upper_bound(v.begin(), v.end(), -v[i]);
		// auto it2=lower_bound(v.begin(), v.end(), -v[i]);
		ll x=(ll)(v.end()-it);
		if(v[i]>0) x--;
		// cout<<x<<endl;
		ct+=x;


	}

	cout<<ct/2<<endl;

	return 0;
}