#include<bits/stdc++.h>
#define f(i, a, n) for(int i=a;i<=n;i++)
// #define mx 200100
#define dbg cout<<"yes"<<endl;
#define pb(a) push_back(a)
#define mk make_pair


using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int dx[]={1, 1, 1, 0, -1, -1,  -1,  0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};

int vis[110][110];
int ar[110][110];

int m,n;

int bfs(int i, int j)
{
	if(i<=0 || j<=0) return 0;
	
	vis[i][j]=1;
	queue<ii> q;
	q.push(mk(i, j));
	while(!q.empty())
	{
		ii p=q.front();
		q.pop();
		for(int k=0;k<8;k++)
		{
			int x=p.first+dx[k];
			int y=p.second+dy[k];
			if(x<1 || x>m || y<1 || y>n) continue;
			else if(ar[x][y]==0 || vis[x][y]==1) continue;

			vis[x][y]=1;
			q.push(mk(x, y));
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	

	while(1)
	{
		cin>>m>>n;
		if(m==0) break;

		// dbg;

		f(i, 1,m)
		{
			f(j,  1, n)
			{
				char ch;
				cin>>ch;
				if(i<=0 || j<=0) continue;
				if(ch=='@') ar[i][j]=1;
				else ar[i][j]=0;
			}
		}

		
		memset(vis, 0, sizeof vis);

		int ans=0;

		f(i, 1,m)
		{
			f(j, 1, n)
			{
				if(i<=0 || j<=0) continue;
				if(ar[i][j]==1 and vis[i][j]==0)
				{
					ans++;

					bfs(i, j);

				}
			}
		}

		cout<<ans<<endl;
	}

	// dbg;

	
	return 0;
}