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

	int n;
	cin>>n;

	int ar[n+10];
	f(i, n)
	{
		cin>>ar[i];

	}

	f(i, n)
	{
		if(ar[i]>=0) ar[i]=-ar[i]-1;
	}

	int ct=1;

	// f(i, n)
	// {
	// 	if(ar[i]!=-1) ct=i;
	// }

	f(i, n)
	{
		if(ar[i]<ar[ct] && ar[i]!=-1) ct=i;
	}
	if(n%2)

	ar[ct]=-ar[ct]-1;

	f(i, n)
	{
		cout<<ar[i]<<" ";
	}
	
	return 0;
}

/**
3
0 0 7

*/