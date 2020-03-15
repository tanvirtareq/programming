#include<bits/stdc++.h>
#define ll long long
using namespace std;

void prn(set<ll> s)
{
	cout<<"YES"<<endl;
	for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		set<ll> v;
		for(ll i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				v.insert(i);
				n=n/i;
				if(v.size()==2) break;
			}
		}

		if(v.size()==3)
		{
			prn(v);
		}

		else
		{
			if(n>1) v.insert(n);


			if(v.size()==3) prn(v);

			else
				cout<<"NO"<<endl;

		}
	}


	return 0;
}