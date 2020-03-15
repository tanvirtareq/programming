#include<bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;

ll dpt[510][20010];

ll n, m;
vector<ll> ad[510];

void clr()
{
	for(ll i=0;i<510;i++) ad[i].clear();
}

ll dpf(ll u, ll p, ll vl)
{
	if(ad[u].size()==1) return m/vl; 
	ll ans=0;
	if(dpt[u][vl]!=-1) return dpt[u][vl];

	for(ll i=vl;i<=m;i+=vl)
	{
		ll f=1;
		for(auto it: ad[u]){
			if(it==p) continue;
			f=(f*dpf(it, u, i))%md;
		}
		ans=(ans+f)%md;
	}
	return dpt[u][vl]=ans;
}


int main()
{

	ll t;

	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &m);
		memset(dpt, -1, sizeof dpt);
		clr();
		for(ll i=1;i<n;i++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			ad[x].push_back(y);
			ad[y].push_back(x);
		}

		ll ans=0;

		for(ll i=1;i<=m;i++)
		{
			ll f=1;
			for(auto it: ad[1]){
				f=(f*dpf(it, 1, i))%md;
			}
			ans=(ans+f)%md;
		}
		printf("%lld\n", ans);

		
		
	}


	return 0;
}