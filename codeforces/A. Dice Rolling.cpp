#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

void dfs(vector<int> v[], int r, int vis[])
{
	for(int i=0;i<v[r].size();i++)
	{
		int x=v[r][i];
		if(vis[x]!=1)
		{
			vis[x]=1;
			dfs(v, x, vis);
		}
	}
	return;
}

void topsort(std::vector<int> v[], int indeg[], int n)
{

    queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0) q.push(i);
	}

	while(!q.empty())
	{
		int x=q.front();

		cout<<x<<" ";
		q.pop();

		for(int i=0;i<v[x].size();i++)
		{
			indeg[v[x][i]]--;
			if(indeg[v[x][i]]==0) q.push(v[x][i]);
		}
	}
	return;

}

int main()
{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);

		int t, n;
		cin>>t;
		while(t--)
		{
			int x;
			cin>>x;
			cout<<ceil((double)x/7)<<endl;
		}

	return 0;
}
