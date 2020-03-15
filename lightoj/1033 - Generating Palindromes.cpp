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
int rc(int i, int j)
{
	if(i>=j) return 0;
	if(ar[i][j]!=-1) return ar[i][j];
	if(s[i]==s[j]) return rc(i+1, j-1);
	return ar[i][j]=1+min(rc(i, j-1), rc(i+1, j));
}


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
		memset(ar, -1, sizeof ar);
		cout<<"Case "<<i<<": "<<rc(0, s.size()-1)<<endl;
	}



	return 0;
}