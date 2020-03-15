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

int main()
{
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);

		vector<int>emt[1100];

	int t, n, i, j;



	while(cin>>n)
	{
		if(n==0) return 0;

	vector<int> v[1100];
	while(cin>>i)
	{
		if(i==0) break;
		while(cin>>j)
		{
			if(j==0) break;

			v[i].push_back(j);

		}

	}
	int q;
		cin>>q;
		while(q--)
		{
			int vis[1100]={0};
			int x, c=0;
			cin>>x;

			dfs(v, x, vis, &c);
			cout<<n-c;

			for(int i=1;i<=n;i++)
			{
				if(vis[i]!=1)
					cout<<" "<<i;
			}
			cout<<endl;
		}

	}


	return 0;
}
