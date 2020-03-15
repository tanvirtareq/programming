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
		int a[20]={0};
		memset(a, 0, sizeof a);
		int n;
		cin>>n;
		string x[20];
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			a[x[i][3]-'0']=1;
		}
		map<string, int> mp;
		mp[x[1]]=1;

		for(int i=2;i<=n;i++)
		{
			if(mp[x[i]]==1)
			{
				ct++;
				for(int j=0;j<10;j++)
				{
					if(a[j]==0)
					{
						a[j]=1;
						x[i][3]=j+'0';
						break;
					}
				}
			}
			mp[x[i]]=1;
		}

		cout<<ct<<endl;
		for(int i=1;i<=n;i++) cout<<x[i]<<endl;
	}

	return 0;
}