#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		priority_queue <ll, vector<ll>, greater<ll> > pq;
		for(ll i=0;i<n;i++) 
		{
			ll x;
			cin>>x;
			pq.push(x);
		}
		// cout<<pq.size()<<endl;
		int f=0; 
		while(pq.size()>1)
		{
			ll p=pq.top();
			if(p==2048)
			{
				cout<<"YES"<<endl;
				f=1;
				break;
			}
			pq.pop();
			if(p!=pq.top()) continue;

			ll q=pq.top();
			pq.pop();
			pq.push(p+q);

		}
		if(f) continue;
		if(pq.top()==2048) cout<<"YES"<<endl;
		else
		{
			if(pq.size()==1)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				ll p=pq.top();
				pq.pop();
				if(p+pq.top()==2048) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}

	}


	return 0;
}