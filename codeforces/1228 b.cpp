#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

ll m, n, r[1100], c[1100];

int invalid(int i, int j)
{
	// cout<<r[i]<<" "<<c[j]<<endl;

	// return (((r[i]==j) and (c[j]<i)) or ((c[j]==i) and (r[i]<j))); 
	if((r[i]==j) and (c[j]>i)) return 1;
	if((c[j]==i) and (r[i]>j)) return 1;
	return 0; 

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n>>m;


	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		r[i]++;
	}

	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		c[i]++;
	}

	ll ans=1;
	int f=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r[i]<j and c[j]<i){
			 ans=(ans*2)%md;
			 f=0;
			}

			if(invalid(i, j)) 
			{
				// cout<<i<<" "<<j<<endl;
				cout<<0<<endl;
				// cout<<r[i]<<" "<<c[j]<<endl;
				// cout<<((c[j]==i) and (r[i]>j))<<endl;
				return 0;
			}
		}
	}

	cout<<ans<<endl;

	
	return 0;
}