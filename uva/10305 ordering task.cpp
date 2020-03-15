#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

void dfs(vector<int> v[], int r, int vis[], int *c)
{
	for(int i=0;i<v[r].size();i++)
	{
		int x=v[r][i];
		if(vis[x]!=1)
		{
			vis[x]=1;
			(*c)++;
			dfs(v, x, vis, c);
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

	int t, n, i, j, m;



	while(cin>>n>>m)
	{
		if(n==0 and m==0) return 0;

		vector<int> v[1100];
		int s[1100];

		int indeg[1100]={0};

		while(m--)
		{
			cin>>i>>j;
			v[i].push_back(j);
			indeg[j]++;
		}

		topsort(v, indeg, n);

		cout<<endl;
	}

	return 0;
}
