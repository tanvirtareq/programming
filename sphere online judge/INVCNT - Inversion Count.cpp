#include<bits/stdc++.h>
#define f(i, a, n) for(ll i=a;i<=n;i++)
// #define mx 200100
#define dbg cout<<"yes"<<endl;
#define pb(a) push_back(a)


using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

ll mx;

ll invc(ll i,ll j, ll a[], ll b[])
{

	
	if(j<i) return 0;
	if(j==i)
	{
		b[i]=a[i];
		return 0;
	}

	ll b1[mx],b2[mx];

	ll md=(i+j)/2;
	ll inc1=invc(i, md, a, b1);
	ll inc2=invc(md+1, j, a, b2);

	ll ans=inc1+inc2;

	ll i1=i, i2=md+1, ai=i;

	while(i1<=md and i2<=j)
	{
		if(b1[i1]<=b2[i2])
		{
			b[ai]=b1[i1];
			ai++;
			i1++;
		}
		else 
		{
			ans+=md-i1+1;
			b[ai]=b2[i2];
			ai++;
			i2++;
		}
	} 

	while(i1<=md)
	{
		b[ai]=b1[i1];
		ai++;
		i1++;
	}
	while(i2<=j)
	{
		b[ai]=b2[i2];
		ai++;
		i2++;
	}
	// cout<<i<<" "<<j<<" "<<ans<<endl;
	return ans;

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll q;
	cin>>q;

	while(q--)
	{
		ll n;
		cin>>n;

		mx=n+10;

		ll ar[mx];


		f(i, 0, n-1)
		{
			cin>>ar[i];
		}

		ll br[mx];
		// cout<<n<<endl;

		cout<<invc(0, n-1,ar, br)<<endl;

	}

	
	return 0;
}