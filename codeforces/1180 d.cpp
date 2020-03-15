#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;



int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n, m;
	// cin>>n>>m;
	scanf("%d%d", &n, &m);

	for(int i=1;i<=n*m;i++)
	{
		if(i%2==1)
		{
			int j=ceil((double)i/2.0);
			int r=(j-1+n)%n+1;
			int c=ceil((double)j/n);
			// cout<<r<<" "<<c<<endl;
			printf("%d %d\n",r, c );
		}
		if(i%2==0)
		{
			int j=n*m-i/2+1;

			int r=(j-1+n)%n+1;
			int c=ceil((double)j/n);
			// cout<<r<<" "<<c<<endl;
			printf("%d %d\n",r, c );
		}

	}

	return 0;
}

