#include<bits/stdc++.h>
#define ii pair<int, int> 
#define ll long long unsigned

using namespace std;

ll n, k, ar[1100000];

ll cr(int m)
{
	ll ct=ar[1];
	ll fc=1;
	ll tk=1;
	for(int i=2;i<=n;i++)
	{
		ct=max(ct, ar[i]);
		tk++;
		if(ct*tk>m)
		{
			ct=ar[i];
			fc++;
			tk=1;
		}

	}
	return fc;
}


ll hasaniba(int m)
{
	ll ct=ar[1];
	ll fc=1;
	ll tk=1;
	ll mx=ar[1];
	for(int i=2;i<=n;i++)
	{
		ct=max(ct, ar[i]);
		tk++;
		if(ct*tk>m)
		{
			ct=ar[i];
			fc++;
			tk=1;
			mx=max(mx, ar[i]);
		}
		else mx=max(mx, ct*tk);

	}
	return mx;
}

int main()
{

	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>k;
		ll mx=0;
		ll mn=INT_MAX;

		for(int i=1;i<=n;i++) cin>>ar[i], mx=max(mx, ar[i]), mn=min(mn, ar[i]);

		ll st=mn;
		ll ed=mx*n;

		while(st<ed)
		{
			ll m=(st+ed)/2;
			if(cr(m)<=k) ed=m;
			else st=m+1;
		}

		ll m=(st+ed)/2;
		cout<<hasaniba(ed)<<endl;
	}

	return 0;
}