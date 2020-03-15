#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof a)
#define pb(a) push_back(a)
#define mx 150010

#define f(i, b, n) for(ll i=b;i<=n;i++)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

ll sgtre[4*mx],  a[mx];

ll up(ll pos, ll l, ll r, ll val)
{
	// cout<<pos<<" "<<l<<" "<<r<<endl;

	if(l==r)
	{
			if(sgtre[pos]==0)
			{
				sgtre[pos]=1;
				a[l]=val;
				// cout<<l<<endl;

				return 1;
			}
			return 0;

	}

	ll lft=2*pos;
	ll rt=lft+1;
	ll md=(l+r)/2;

	ll f=1;

	if(sgtre[lft]==0) 
	{
		f= up(lft, l, md, val);
	}
	else if(sgtre[rt]==0)
	{
		if(up(lft, l, md, val)==0)
		{

			f= up(rt, md+1, r, val);
			// cout<<f<<" "<<rt<<endl;
		}

		// else f= up(lft, l, md, val);
	}
	else f= up(rt, md+1, r, val);

	sgtre[pos]=sgtre[lft]+sgtre[rt];

	return f;
}

ll gt(ll pos,ll l, ll r, ll idx)
{
	// if(sgtre[l]==0 and sgtre[r]==0) return 0;

	if(l==r)
	{
		sgtre[pos]=0;
		if(a[l]==0 ) return 0;

		cout<<a[l]<<endl;
		a[l]=0;
		return 1;
	}

	ll lft=2*pos;
	ll rt=lft+1;
	ll md=(l+r)/2;
	ll f;

	if(sgtre[lft]>=idx)
	{
		f=gt(lft, l, md, idx);
	}
	else 
	{
		f=gt(rt, md+1, r, idx-sgtre[lft]);
	}
	sgtre[pos]=sgtre[lft]+sgtre[rt];
	return f;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll t;
	cin>>t;
	// cout<<t<<endl;

	f(i, 1, t)
	{
		ll n,k, tot;
		cin>>n>>k;
		// cout<<n<<" "<<k<<endl;
		tot=n+k;

		clr(sgtre);
		clr(a);

		f(j, 1, n)
		{
			ll x;
			cin>>x;
			// cout<<x<<" ";
			up(1,1, tot,  x);
		}

		cout<<"Case "<<i<<":"<<endl;

		while(k--)
		{
			char ch;
			ll x;
			cin>>ch>>x;
			if(ch=='a') up(1,1, tot,  x);

			else if(gt(1, 1, tot, x)==0)  cout<<"none"<<endl;
		}
	}


	return 0;
}