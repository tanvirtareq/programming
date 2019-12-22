#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int ad[30][30];
int vis[30];
int as[30];

int ct;
void dfs(int rt)
{
	vis[rt]=1;
	for(int i=0;i<=26;i++)
	{
		if(ad[rt][i] and vis[i]==0)
		{
			vis[i]=1;
			dfs(i);
		}
	}
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	#endif

	int n;
	cin>>n;

	
	
	memset(ad, 0, sizeof ad);

	for(int i=1;i<=n;i++)
	{

		string x;
		cin>>x;
		int rt=x[0]-'a';
		as[rt]=1;
		for(int j=1;j<x.size();j++)
		{
			int y=x[j]-'a';
			ad[rt][y]=1;
			ad[y][rt]=1;
			as[y]=1;
		}
	}

	for(int i=0;i<=27;i++)
	{
		if(as[i]==1 and vis[i]==0)
		{
			vis[i]=1;
			dfs(i);
			ct++;
		}
	}
	cout<<ct<<endl;

	return 0;
}