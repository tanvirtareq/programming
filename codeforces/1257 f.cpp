#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define xd 101000

using namespace std;
typedef long long ll;

vector<pair<string, ll> > v;

ll bs(string str, ll i, ll j)
{
	if(i>j) return -1;

	ll m=(i+j)/2;

	if(v[m].first==str) return v[m].second;

	if(v[m].first>str) return bs(str, i, m-1);
	else return bs(str, m+1, j);
}

void print(ll a, ll b)
{
	ll x=(a<<15)+b;
	printf("%lld\n", x);
	return;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n;
	scanf("%lld", &n);
	ll ar[n+10], b[n+10];
	for(ll i=1;i<=n;i++) scanf("%lld", &ar[i]);
	ll m=(1LL<<15);

	

	for(ll i=0;i<m;i++)
	{
		ll mx=0;
		for(ll j=1;j<=n;j++)
		{
			b[j]=ar[j]^i;
			for(ll k=15;k<=30;k++) 
				if((b[j]&(1LL<<k))) b[j]=b[j]^(1LL<<k);
			b[j]=__builtin_popcount(b[j]);	
			mx=max(mx, b[j]);
		}

		string str;

		for(ll j=1;j<=n;j++)
		{
			str.push_back(mx-b[j]+33);
		}

		v.push_back(make_pair(str, i));

	}

	sort(v.begin(), v.end());

	for(ll i=0;i<m;i++)
	{
		ll x=i<<15;

		ll mn=INT_MAX;

		for(ll j=1;j<=n;j++)
		{
			b[j]=ar[j]^x;
			for(ll k=0;k<15;k++)
				 if((b[j]&(1LL<<k))) b[j]=b[j]^(1LL<<k);
			b[j]=__builtin_popcount(b[j]);
			mn=min(mn, b[j]);
		}

		string str;

		for(ll j=1;j<=n;j++)
		{
			str.push_back(b[j]-mn+33);
		}

		ll fc=bs(str, 0, m-1);

		if(fc!=-1)
		{
			print(i, fc);
			return 0;
		}
	}


	printf("-1\n");

	
	return 0;
}
