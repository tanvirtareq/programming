#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(ll i=a;i<=b;i++)
#define	mx	1500000
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n, i;
	cin>>n>>i;
	i=i*8;

	ll k=pow((double)2, (double)i/(double)n);

	while(k>0 and ceil(log2(k))>((double)i/(double)n))
		k--;

	if(k==0)
	{
		cout<<n<<endl;
		return 0;
	}

	map<ll, ll> mp;
	// cout<<k<<endl;

	vi v;

	f(i, 1, n)
	{
		ll x;
		cin>>x;
		if(mp[x]==0)
		{
			mp[x]=1;
			v.pb(x);
		}
		else mp[x]++;
		
	}
	// cout<<v.size()<<endl;
	// cout<<k<<endl;

	if(k>=v.size())
	{
		cout<<0<<endl;
		return 0;
	}

	sort(v.begin(), v.end());

	ll bf[n+10], af[n+10];
	bf[0]=0;
	ll ct=mp[v[0]];

	for(ll i=1;i<v.size();i++)
	{
		
		
		bf[i]=ct;
		ct+=mp[v[i]];
	}

	af[v.size()-1]=0;
	ct=mp[v[v.size()-1]];

	for(ll i=v.size()-2;i>=0;i--)
	{
		
		af[i]=ct;
		
		ct+=mp[v[i]];
	}

	ll mn=LONG_MAX;

	for(ll i=0;i+k-1<v.size();i++)
	{
		mn=min(mn, bf[i]+af[i+k-1]);
	}
	if(mn!=LONG_MAX)
	cout<<mn<<endl;
	else cout<<0<<endl;


	return 0;
}