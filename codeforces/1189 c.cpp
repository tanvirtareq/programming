#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;

	cin>>n;

	int a[n+10];

	int x=log2(n);
	pair<int, int> v[x+10][n+10];

	f(i, n)
	{
		cin>>a[i];
		v[0][i]=make_pair(a[i], 0);
	}

	

	for(int i=1;i<=x;i++)
	{
		int tmp=1<<(i-1);
		// cout<<tmp<<endl;
		for(int j=1;j+tmp<=n;j++)
		{

			int f1=v[i-1][j].first;
			int f2=v[i-1][j+tmp].first;

			int s1=v[i-1][j].second;
			int s2=v[i-1][j+tmp].second;

			int s=s1+s2+(f1+f2)/10;
			int f=(f1+f2)%10;
			// cout<<s<<" "<<f<<endl;

			v[i][j]=make_pair(f, s);

		}

		// cout<<endl<<endl;
	}

	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;

		int tm=r-l+1;
		// cout<<tm<<endl;
		int tmp=log2(tm);
		cout<<v[tmp][l].second<<endl;
	}

	
	return 0;
}