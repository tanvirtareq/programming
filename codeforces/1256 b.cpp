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
	int ar[200], br[200];
	while(q--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
			br[ar[i]]=i;
		}
		int ct=n-1;

		for(int i=1;i<=n;i++)
		{
			if(ct<=0) break;

			int id=br[i];

			if(id-ar[id]>ct) continue;

			while(ar[id]<id)
			{
				if(ct<=0) break;
				// cout<<ct<<endl;
				swap(ar[id], ar[id-1]);
				// cout<<ar[id]<<" "<<ar[id-1]<<endl;
				// for(int i=1;i<=n;i++) cout<<ar[i]<<" ";
				// 	cout<<endl;
				br[ar[id]]=id;
				br[ar[id-1]]=id-1;
				id--;
				ct--;
			}
		}

		for(int i=1;i<=n;i++) cout<<ar[i]<<" ";
		cout<<endl;
	}

	return 0;
}