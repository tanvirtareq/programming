#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mk(a, b) make_pair(a, b);
#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	ll n;
	cin>>n;

	string s;
	cin>>s;

	std::vector<ll> v[28];
	

	for(ll i=0;i<s.size();i++)
	{
		v[s[i]-'a'].pb(i+1);

	}

	ll m;
	cin>>m;

	while(m--)
	{
		

		string x;
		cin>>x;

		ll ct =-1;

		int cnt[28]={0};
		for(ll i=0;i<x.size();i++)
		{
			cnt[x[i]-'a']++;
			
		}


		for(int i=0;i<26;i++)
		{
			if(cnt[i]>0)
			ct=max(ct, v[i][cnt[i]-1]);
		}
		// dbg;

		cout<<ct<<endl;

	}

	return 0;
}