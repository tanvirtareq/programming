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

	int q;
	cin>>q;
	while(q--)
	{
		int ar[3];
		cin>>ar[0]>>ar[1]>>ar[2];
		sort(ar, ar+3);

		int ct=min(ar[0], ar[2]-ar[1]);
		ar[0]-=ct;
		ar[2]-=ct;
		if(ar[0]==0) ct+=min(ar[1], ar[2]);
		else
		{
			int x=min(ar[0]/2, ar[1]);
			ct+=x;
			ar[0]-=x;
			ar[1]-=x;
			x=min(ar[0], ar[2]);
			ct+=x;
			ar[0]-=x;
			ar[2]-=x;
			ct+=min(ar[1], ar[2]);

		}
		// ct=ar[0];
		// ar[2]-=ar[0];
		// ct+=min(ar[1], ar[2]);
		cout<<ct<<endl;
	}

	return 0;
}