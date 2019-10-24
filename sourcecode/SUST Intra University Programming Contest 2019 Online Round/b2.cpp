#include<bits/stdc++.h>

#define f(i, n) for(ll i=1;i<=n;i++)
#define sci(a) scanf("%d", &a)
#define wi(a) prllf("%d\n", a)
#define dbg prllf("yes\n")

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> ii;
typedef priority_queue<ll> pqi;
typedef priority_queue<ll , vector<ll> , greater<ll> > mnpqi;

ll n, ar[30];

ll tab[30][30];
ll xr[30][30];

ll dp(ll i, ll j)
{

	if(xr[i][j]!=0) return 1;

	// if(tab[i][j]!=-1) return tab[i][j];

	ll ct=LONG_MAX;
	int flg=0;

	for(ll k=i;k<j;k++)
	{
		ll p=dp(i, k);
		ll q=dp(k+1, j);

		if(p!=0 && q!=0)
		{
			flg=1;
			ct=min(ct, p+q);
		}

	}

	if(flg==0) return 0;

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

	for(ll i=1;i<=n;i++)

	{

		xr[i][i]=ar[i];
		for(ll j=i+1;j<=n;j++)
		{
			xr[i][j]=xr[i][j-1]^ar[j];
		}
	}

	ll ans=dp(1, n);

	if(ans>0)
	cout<<ans<<endl;

	else cout<<-1<<endl;


	return 0;
}
