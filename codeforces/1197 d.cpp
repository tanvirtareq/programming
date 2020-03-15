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
 
	ll n, m, k;
	cin>>n>>m>>k;
 
	ll ar[n+10];
	f(i, n)
	{
		cin>>ar[i];
		// ar[i]-=ceil((double)k/m);
		// cout<<ar[i]<<" ";
	}
	// cout<<endl;


	ii cr[n+10];
	ll t=0;
	clr(cr);
	int fc=0;
	f(i, n)
	{
		t=cr[i].second;
		if(t%m==0) fc++;
		cr[i].first=cr[i-1].first+ar[i]-k*fc;
		if(cr[i].first>0)
		{
			// cout<<cr[i].first<<endl;
			cr[i].second++;
		}
		else 
		{
			cr[i].first=0;
			t=0;
			cr[i].second=t;
			fc=0;
		}
	}

	f(i, n)
	{
		cout<<cr[i].first<<" "<<cr[i].second<<endl;
	}
 
	ll ct=0;
	ll mx=0;
	
 
	f(i, n)
	{
		ct+=ar[i];
		t++;
		if(ct-k*(ll)ceil((double)t/m)<=0) ct=0, t=0;
 
		if(ct-k*(ll)ceil((double)t/m)<=ar[i]-k*(ll)ceil((double)1/m))
		{
			ct=ar[i];
			t=1;
		}
 
		// cout<<ct<<endl;
		mx=max(mx, (ct-k*(ll)ceil((double)t/m)));
	}
	cout<<mx<<endl;
 
 
	return 0;
}