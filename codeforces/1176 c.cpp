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

	int n;
	cin>>n;

	map<int, int> mp;

	f(i, n)
	{
		int x;
		cin>>x;
		if(x==4) mp[4]++;
		if(x==8) mp[8]=min(mp[8]+1, mp[4]);
		if(x==15) mp[15]=min(mp[15]+1, mp[8]);
		if(x==16) mp[x]=min(mp[x]+1, mp[15]);
		if(x==23) mp[x]=min(mp[x]+1, mp[16]);
		if(x==42) mp[x]=min(mp[x]+1, mp[23]);
		// mp[x]++;
		// cout<<mp[x]<<endl;
		
		
	}

	int k=n-n%6;

	int mx=min(k, mp[4]);
	mx=min(mx, mp[8]);
	mx=min(mx, mp[15]);
	mx=min(mx, mp[16]);
	mx=min(mx, mp[23]);
	mx=min(mx, mp[42]);

	cout<<n-6*mx<<endl;

	return 0;
}