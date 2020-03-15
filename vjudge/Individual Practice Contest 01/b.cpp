#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(ll i=a;i<=b;i++)
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

string a, b;
ll dp[1100][1100];
ll lcs(int i,int j)
{
	if(i>=a.size() || j>=b.size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	return dp[i][j]=max((a[i]==b[j])? 1+lcs(i+1, j+1): -1 ,  max(lcs(i+1, j), lcs(i, j+1)));
}

int main()
{
	ll t;
		cin>>a>>b;
		memset(dp,  -1, sizeof dp);
		printf("%lld ",lcs(0, 0));
	return 0;
}