#include<bits/stdc++.h>
#define f(i, n) for(ll i=1;i<=n;i++)
#define clr(a) memset(a, 0, sizeof a)
 
using namespace std;
 
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, ll> mnpq;
 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll q;
	cin>>q;

	while(q--)
	{

		ll n;
		cin>>n;
		ll f=0;
		ll ct=0;

		ll a=0, b=0, c=0;

		f(i,n)
		{
			int x;
			cin>>x;
			if(x%3==0) a++;
			else if(x%3==1) b++;
			else c++;
		}

		ll ans=a+min(b,c);
		ans+=(b>c)?max(0LL, b-min(b, c))/3:max(0LL, c-min(b, c))/3;
		

		cout<<ans<<endl;
	}
 

	return 0;
}