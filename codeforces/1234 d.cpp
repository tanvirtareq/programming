#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" ="<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

string x;

ll tree[400010];

void update(ll node, ll start, ll end, ll idx, ll val)
{
	if(start==end)
	{
		x[idx]=val+'a';
		tree[node]=(1LL<<val);
		// cout<<idx<<" "<<tree[node]<<endl;
	}

	else 
	{
		ll mid=(start+end)/2;

		if(start<=idx and idx<=mid)
		{
			update(2*node, start, mid, idx, val);
		}

		else 
		{
			update(2*node+1, mid+1, end, idx, val);
		}

		tree[node]=(tree[2*node]|tree[2*node+1]);
		// cout<<tree[node]<<endl;
	}
}

ll query(ll node, ll start, ll end, ll l,ll r)
{
	// dbg(node);
	// cout<<start<<" "<<end<<endl;
	// cout<<l<<" ash "<<r<<endl;
	if(r<start or end<l) return 0;

	if((l<=start) and (end<=r)) return tree[node];

	ll mid=(start+end)/2;

	ll p1=query(2*node, start, mid, l, r);
	ll p2=query(2*node+1, mid+1, end, l, r);
	// dbg(p1);

	return p1|p2;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	
	cin>>x;
	// dbg(x);

	for(int i=0;i<x.size();i++)
	{
		update(1, 0, x.size()-1, i, (x[i]-'a'));

	}

	ll n;
	cin>>n;
	// dbg(n);

	while(n--)
	{
		ll a, b, c;
		char ch;
		cin>>a;
		if(a==1)
		{
			cin>>b>>ch;
			update(1, 0, x.size()-1, b-1, ch-'a');
			// dbg(b);
		}

		else if(a==2)
		{
			cin>>b>>c;
			// dbg(b);
			// dbg(c);
			ll fc=query(1, 0, x.size()-1, b-1, c-1);
			// dbg(fc);
			cout<<__builtin_popcount(fc)<<endl;
		}
	}


	return 0;
}