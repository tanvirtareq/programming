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
		int f=0;
		ll ct=0;
		while(n!=1)
		{
			ct++;
			if(n%2==0) n=n/2;

			else if(n%3==0) n=2*n/3;

			else if(n%5==0) n=4*n/5;

			else
			{
				f=1;
				break;
			}
		}

		f? cout<<"-1"<<endl:cout<<ct<<endl;
	}
 

	return 0;
}