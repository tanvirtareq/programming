#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

#define memo(a, n, i) (for(int i=0;i<=n;i++) a[i]=i)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	string x;
	cin>>n>>k;
	cin>>x;

	if(x.size()==1 && k)
	{
		cout<<0<<endl;
		return 0;
	}

	if(x[0]=='-')
	{
		for(int i=1;i<n && k;i++)
		{
			if(x[i]!='9')
			{
				k--;
				x[i]='9';
			}
		}
		cout<<x<<endl;
		return 0;
	}

	if(x[0]!='1' && k)
	{
		x[0]='1';
		k--;
	}

	for(int i=1;i<x.size() && k; i++)
	{
		if(x[i]!='0') 
		{
			x[i]='0';
			k--;
		}

	}
	cout<<x<<endl;

	return 0;
}