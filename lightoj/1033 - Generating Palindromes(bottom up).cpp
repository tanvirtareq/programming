#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(int i=a;i<=b;i++)
#define	mx	1500000
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

string s;
int ar[110][110];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	f(i,1, t)
	{		
		cin>>s;
		memset(ar, 0, sizeof ar);
		string rv=s;
		reverse(rv.begin(), rv.end());
		int n=s.size();
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				(s[j]==rv[k])? ar[j+1][k+1]=ar[j][k]+1: ar[j+1][k+1]=max(ar[j][k+1], ar[j+1][k]);
		cout<<"Case "<<i<<": "<<n-ar[n][n]<<endl;
	}



	return 0;
}