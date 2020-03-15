#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(ll i=a;i<=b;i++)
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

ll n, x, d, ar[2000];

ll hasa(ll i)
{
	ll val=0;
	ll mx=-300000000000;
	ll mn=-mx;
	int f=0;
	for(ll j=0;j<n;j++)
	{

		if(i&(1LL<<j))
		{
			val+=ar[j];
			f=1;
			mx=max(mx, ar[j]);
			mn=min(mn, ar[j]);
		}
	}
	if(f==0) return 0;
	if(val>=x and mx-mn<=d) return 1;
	return 0;
}

int main()
{
	cin>>n>>x>>d;
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	ll mx=(1LL<<n)-1;
	ll ans=0;

	for(ll i=1;i<=mx;i++)
	{
		ans+=hasa(i);
	}
	cout<<ans<<endl;

	return 0;
}