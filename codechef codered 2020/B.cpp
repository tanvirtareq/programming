#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int n, m;

vector< vector<long long> > dp[3];

long long DP(int i, int j, int muv) {
	muv %= 2;
	if(j > n or j < 1) return 0;
	if(i >= m) return (i == m and muv % 2 == 1);

	if(dp[muv][i][j] != -1) return dp[muv][i][j];
	long long ret = 0;
	ret = DP(i+2, j+1, muv+1); ret %= mod;
	ret += DP(i+1, j+2, muv+1); ret %= mod;
	ret += DP(i+2, j-1, muv+1); ret %= mod;
	ret += DP(i+1, j-2, muv+1); ret %= mod;

	return dp[muv][i][j] = ret;
}

int main() {
	cin >> m >> n;

	dp[0]=vector<vector<long long> >(m+1,vector<long long>(n+1));
	dp[1]=vector<vector<long long> >(m+1,vector<long long>(n+1));

	for(int i=0; i<2; i++) for(int j=1; j<=m; j++) for(int k=1; k<=n; k++) dp[i][j][k] = -1;

	long long ans = 0;
	for(int i=2; i<=n; i+=2) ans += DP(1, i, 0), ans %= mod;

	cout << ans;
}