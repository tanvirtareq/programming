#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" ="<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll t;
	cin>>t;
	// dbg(t);
	while(t--)
	{
		ll n;
		cin>>n;
		// dbg(n);
		string x, y;
		cin>>x>>y;
		int i=0;
		int fc=0;

		if(x[0]>'2')
		{
			fc=1;

			if(y[0]<='2')
			{
				 cout<<"NO"<<endl;
				 continue;
			 }
			 
		}
		i++;
		// dbg(fc);


		int fl=0;

		while(i<n)
		{
			// dbg(i);
			if(fc==0)
			{
				if(x[i]<='2')
				{
					i++;
				}
				else
				{

				 fc=1;

				 if(y[i]<='2')
				 {
				 	fl=1;
				 	break;
				 }
				 i++;
				}
			}
			else
			{
				if(y[i]<='2') i++;
				else {

					fc=0;
					if(x[i]<='2')
					{
						fl=1;
						break;
					}
					i++;
				}
			}
		}



		if(fl==0 and fc==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}

	return 0;
}
