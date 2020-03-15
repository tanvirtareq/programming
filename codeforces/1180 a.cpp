#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll rc(int n)
{
	if(n==1) return 1;

	return 4*(n-1)+rc(n-1);
}


int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ll n;
	cin>>n;

	cout<<rc(n)<<endl;

	
	return 0;
}