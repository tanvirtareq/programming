#include<bits/stdc++.h>
#define ii pair<int, int> 
#define ll long long unsigned

using namespace std;

ll power(ll b, ll p)
{
	if(p==0) return 1;
	if(p==1) return b;
	ll x=power(b, p/2);
	x=x*x;
	if(p&1) x*=b;
	return x;
}


int main()
{
	ll l, r, k;
	cin>>l>>r>>k;
	// l=1000000000LL;
	// r=10000000000000000LL;
	// cout<<l*r<<endl;

	// ll f=log((double)l)/log((double)k); 
// cout<<1000000000LL*1000000000000000000LL<<endl;

	// f=max(0LL, f-10);

	// ll ans=power(k, f);

	ll ans;

	ll fc=1;

	ll x=0;
	ans=1;
	ll lst=ans;

	while(1)
	{
		if(ans>=l and ans<=r){ 
			cout<<ans<<" ";
			fc=0;
		}
		if(ans>=r || ans<=0 || lst>ans) break;
		if(log10(ans)+log10(k)>=19) break;

		lst=ans;
		ans*=k;
		x++;
		// if(x==1000) break;
	}
	if(fc) cout<<-1<<endl;

	return 0;
}