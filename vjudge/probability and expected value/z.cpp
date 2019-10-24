#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double dp[10001][10001];
 // pm[100010][100010];
double p[100010];
// bool vis[100010][100010];
int n;

int d(int st, int tk)
{
	// cout<<st<<endl;

	if(st>n)
	{

		// pm[st][tk]=1.0;
		dp[st][tk]=(double)tk*tk;
		return 1;
	}

	d(st+1, tk+1);
	d(st+1, tk);

	dp[st][tk]=dp[st+1][tk+1]*p[st]+dp[st+1][tk]*p[st]+(double)tk*tk*p[st];
	// dp[st][tk]=dp[st+1][tk+1]*p[st];
	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	
	cin>>n;
	cout<<n<<endl;

	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	cout<<n<<endl;

	d(1LL, 0LL);

	cout<<dp[1][0]<<endl;

	return 0;
}