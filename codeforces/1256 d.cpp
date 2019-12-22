#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	#endif

	ll q;
	cin>>q;
	ll ar[200], br[200];
	while(q--)
	{
		ll n, k;
		string x;
		cin>>n>>k>>x;
		n--;
		// cout<<x<<endl;

		ll a1, a0;
		a1=a0=0;

		while(a1<=n)
		{
			if(x[a1]=='1')
			{
				break;
			}
			a1++;
		}
		// cout<<a1<<endl;

		a0=a1+1;
		while(a0<=n and k>0)
		{
			if(x[a0]=='0')
			{
				ll fc=min(k, a0-a1);
				x[a0-fc]='0';
				x[a0]='1';
				k=k-fc;
				a1++;
				// cout<<a0<<endl;
			}
			a0++;
		}
		cout<<x<<endl;
	}

	return 0;
}