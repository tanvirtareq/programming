#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof a)
#define pb(a) push_back(a)
 
#define f(i, b, n) for(ll i=b;i<=n;i++)
 
using namespace std;
 
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
 
ll c[1500+10];
ll lps[1500+10];

struct trie{
	trie *nxt[27];
};

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	string a, b;
 
	ll k;
	cin>>a>>b>>k;

	trie *rt=new trie();

 
	
	c[0]=(b[a[0]-'a']=='0');
 
	f(i, 1, a.size()-1)
	{
		c[i]= (b[a[i]-'a']=='0');
		// cout<<c[i]<<endl;
	}

 	
	ll ct=0;
 
	for(ll i=0;i<a.size();i++)
	{
		trie *cur=rt;
		int cnt=0;
		for(ll j=i;j<a.size();j++)
		{
			cnt+=c[j];
			if(cnt>k) break;

			if(cur->nxt[a[j]-'a']==NULL)
			{
				ct++;
				cur->nxt[a[j]-'a']=new trie();
			}
			cur=cur->nxt[a[j]-'a'];
		}
	}
 
	cout<<ct<<endl;
	
 
	return 0;
}