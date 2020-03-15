#include<bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a;

	cin>>a;
	while(a--)
	{
		int n;
		cin>>n;
		int ans[n+10], ar[n+10];

		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			ar[x]=i;
		}

		int mn=INT_MAX;
		int mx=0;

		for(int i=1;i<=n;i++)
		{
			mn=min(mn, ar[i]);
			mx=max(mx, ar[i]);

			if(mx-mn+1==i) ans[i]=1;
			else ans[i]=0;
		}

		for(int i=1;i<=n;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;

	}

	return 0;
}