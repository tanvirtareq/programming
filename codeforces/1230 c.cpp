#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair


using namespace std;

typedef long long ll;
typedef long long unsigned lu;

int n, m;

int gp[10][10], dvis[10][10], nvis[10], clvis[10];

int chk(int i, int j)
{
	int vis[10];
	for(int k=0;k<=9;k++) vis[k]=0;

	for(int k=1;k<=n;k++)
	{
		if(gp[i][k]) vis[k]=1;
	}

	for(int k=1;k<=n;k++)
	{
		if(gp[j][k] and vis[k]) return 0;
	}

	return 1;
}

int setclr(int i, int j)
{
	for(int k=1;k<=6;k++)
	{
		if(clvis[k]==0)
		{
			dvis[k][k]=1;
			nvis[i]=nvis[j]=1;
			return 0;
		}
	}
	return 0;
}

int clr(int nd)
{

	if(nvis[nd]==0)
	{
		for(int i=1;i<=6;i++)
		{
			int f=0;
			for(int j=1;j<=6;j++)
			{
				if(dvis[i][j]==0)
				{
					nvis[nd]=i;
					f=1;
					break;
				}
			}
			if(f) break;
		}
	}

	queue<int> q;
	q.push(nd);

	while(!q.empty())
	{
		int rt=q.front();
		q.pop();

		for(int i=1;i<=n;i++)
		{
			if(gp[rt][i]==0) continue;
			if(i==rt) continue;
			if(nvis[i]>0)
			{
				dvis[nvis[i]][nvis[rt]]=1;
				dvis[nvis[rt]][nvis[i]]=1;
				cout<<rt<<" fc "<<i<<endl;
				continue;
			}

			for(int j=1;j<=6;j++)
			{
				if(nvis[rt]==j) continue;
				if(dvis[nvis[rt]][j]==0)
				{
					nvis[i]=j;
					dvis[nvis[rt]][j]=1;
					dvis[j][nvis[rt]]=1;
					cout<<rt<<" "<<i<<" "<<nvis[rt]<<" "<<nvis[i]<<endl;
					q.push(i);
					break;
				}
			}
		}
	}

	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	

	cin>>n>>m;

	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		gp[x][y]=1;
		gp[y][x]=1;
	}

	set<int> s;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(chk(i, j)){
				cout<<i<<" "<<j<<endl;
			 setclr(i, j);
			 s.insert(i);
			 s.insert(j);
			}
		}
	}

	set<int>:: iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		clr(*it);
	}
	// cout<<"gh"<<endl;

	for(int i=1;i<=n;i++)
	{
		if(nvis[i]==0)
		clr(i);
	cout<<"gh"<<endl;
	}

	int x=0;

	for(int i=1;i<=6;i++)
	{
		for(int j=i;j<=6;j++)
		{
			x+=(dvis[i][j]>0);
			cout<<i<<" "<<j<<" "<<dvis[i][j]<<endl;
		}
	}

	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<nvis[i]<<endl;
	}

	cout<<x<<endl;


	return 0;
}