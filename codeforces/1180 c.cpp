#include<bits/stdc++.h>
#define f(i, n) for(ll i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef pair<ll, ll> ii;


ll rc(ll n)
{
	if(n==1) return 1;

	return 4*(n-1)+rc(n-1);
}


int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ll n, q;
	cin>>n>>q;
	deque<ll> d;
	deque<ll>::iterator it;

	ll mx=LONG_MIN;
	ll ct=1;

	f(i, n)
	{
		ll x;
		cin>>x;
		d.push_back(x);
		if(x>mx){ 
			ct=i;
			mx=x;
		}

	}
	// cout<<ct<<endl;

	pair<ll, ll> ar[ct+10];

	f(i, ct-1)
	{
		ll a=d.front();
		d.pop_front();
		ll b=d.front();
		d.pop_front();

		// cout<<a<<" "<<b<<endl;
		ar[i]=make_pair(a, b);

		if(a>b)
		{
			d.push_front(a);
			d.push_back(b);
		}
		else 
		{

			d.push_front(b);
			d.push_back(a);
		}
	}

	ll ans[n+10];
	// cout<<d.front()<<endl;

	for(it=d.begin()+1;it!=d.end();it++)
	{
		ans[it-d.begin()]=*it;
		// cout<<it-d.begin()<<" "<<*it<<endl;
	}

	while(q--)
	{

		ll tm;
		cin>>tm;
		// cout<<tm<<endl;

		if(tm<ct)
		{
			cout<<ar[tm].first<<" "<<ar[tm].second<<endl;
		}
		else 
		{

			ll f=tm-(ct-1)-1;
			// cout<<f<<endl;
			cout<<mx<<" "<<ans[f%(n-1)+1]<<endl;
		}
	}


	
	return 0;
}

