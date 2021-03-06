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
ll dp[35][35], l;
ll dp1[35][35][70];
ll lcs(int i,int j)
{
	if(i>=a.size() || j>=b.size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	return dp[i][j]=max((a[i]==b[j])? 1+lcs(i+1, j+1): -1 ,  max(lcs(i+1, j), lcs(i, j+1)));
}

ll rc(int i,int j, int k)
{
	if(i>=a.size()) return (b.size()-j)==(l-k);
	if(j>=b.size()) return (a.size()-i)==(l-k);
	if(dp1[i][j][k]!=-1) return dp1[i][j][k];
	return dp1[i][j][k]=(a[i]==b[j])? rc(i+1, j+1, k+1): rc(i+1, j,k+1)+rc(i, j+1, k+1);
}

int main()
{

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	ll t;
	scanf("%lld", &t);
	f(in,1, t)
	{
		cin>>a>>b;
		memset(dp,  -1, sizeof dp);
		memset(dp1,  -1, sizeof dp1);
		printf("Case %lld: ", in);
		printf("%lld ", l=a.size()+b.size()-lcs(0, 0));
		printf("%lld\n", rc(0, 0, 0));
	}
	return 0;
}