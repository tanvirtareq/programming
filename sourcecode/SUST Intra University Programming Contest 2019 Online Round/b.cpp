#include<bits/stdc++.h>

#define f(i, n) for(int i=1;i<=n;i++)
#define sci(a) scanf("%d", &a)
#define wi(a) printf("%d\n", a)
#define dbg printf("yes\n")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef priority_queue<int> pqi;
typedef priority_queue<int , vector<int> , greater<int> > mnpqi;

int n, ar[30];

int tab[30][30];
int xr[30][30];

int dp(int i, int j)
{

	if(xr[i][j]!=0) return 1;

	// if(tab[i][j]!=-1) return tab[i][j];

	int ct=INT_MAX;

	for(int k=i;k<j;k++)
	{
		int p=dp(i, k);
		int q=dp(k+1, j);

		if(p!=0 && q!=0)
		{
			ct=min(ct, p+q);
		}

	}

	return tab[i][j]=ct;

}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	cin>>n;

	memset(tab, -1, sizeof tab);

	f(i, n)
	{
		cin>>ar[i];

	}

	for(int i=1;i<=n;i++)

	{

		xr[i][i]=ar[i];
		for(int j=i+1;j<=n;j++)
		{
			xr[i][j]=xr[i][j-1]^ar[j];
		}
	}

	int ans=dp(1, n);

	cout<<ans<<endl;


	return 0;
}
