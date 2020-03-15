#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define v(a) vector<a>
#define p(a, b) pair<a,b> 

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pqi;
typedef priority_queue<ll , vi, greater<ll> > mnpqi;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string x;
	cin>>x;

	ll ct=0;
	ll vt=0;
	ll vv=0;
	ll ot=0;

	vi vfv, vov;

	if(x.size()<2)
	{
		cout<<0<<endl;
		return 0;
	}

	for(ll i=1;i<x.size();i++)
	{
		if(x[i]=='o')
		{
			if(vt>0) vfv.push_back(vt);
			vt=0;
			if(vv==1)
			{
				ot++;
			}
		}
		else if(x[i]=='v' && x[i-1]=='v')
		{
			vv=1;
			if(ot>0) vov.push_back(ot);
			ot=0;
			vt++;
		}
	}
	if(vt>0) vfv.push_back(vt);

	if(vfv.size()<2 || vov.size()<1)
	{
		cout<<0<<endl;
		return 0;
	}

	ll bfr=vfv[0];

	ll aft=vfv[1];

	for(ll i=2;i<vfv.size();i++)
	{
		aft+=vfv[i];
	}

	ll ans=bfr*vov[0]*aft;

	for(ll i=1;i<vov.size();i++)
	{
		aft-=vfv[i];
		bfr+=vfv[i];
		ans+=bfr*vov[i]*aft;


	}
	cout<<ans<<endl;



	return 0;
}