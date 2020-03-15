#include<bits/stdc++.h>
#define ll long long
#define MX 200100

using namespace std;

int n, c[MX], wh[MX], bl[MX], mx[MX];
vector<int> ad[MX];

void dfs(int r, int p)
{
	if(c[r]==1) wh[r]++;
	else bl[r]++;
	mx[r]=1;

	for(int i=0;i<ad[r].size();i++)
	{
		int v=ad[r][i];
		if(v==p) continue;

		dfs(v, r);

		mx[r]=max(mx[r], mx[v]);
		wh[r]+=wh[v];
		bl[r]+=bl[v];
	}

	mx[r]=max(mx[r], abs(wh[r]-bl[r]));
	return ;

}


int main()
{

	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];

	for(int i=1;i<n;i++)
	{
		int x, y;
		cin>>x>>y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}

	dfs(1, -1);
	

	return 0;
}