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

    queue<string> q;
    map<string>:: iterator it;

	for(it=indeg.begin();it!=indeg.end();it++)
	{
		if(it->first==0) q.push(it->second);
	}

	while(!q.empty())
	{
		string x=q.front();

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

		map<string, vector<string> >mp;
		int s[1100];

		map<string> indeg;
		cin>>m;

		while(m--)
		{

			string x, y;
			cin>>x>>y;
			v[x].push_back(y);
			indeg[y]++;
		}

		topsort(v, indeg, n);

		cout<<endl<<endl;
	}

	return 0;
}
