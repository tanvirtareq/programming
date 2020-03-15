#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int mx=0;
		int ar[n+10];
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
			// cout<<ar[i]<<endl;
			mx=max(mx, ar[i]);
		}
		int f=0;
		// cout<<mx<<endl;
		for(int i=1;i<=n;i++)
		{
			if((mx-ar[i])%2==1) f=1;
		}
		// cout<<f<<endl;
		if(f) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}


	return 0;
}