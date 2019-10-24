#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(int i=a;i<=b;i++)
#define	mx	1500000
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, x, y;
	cin>>n>>x>>y;

	int ar[n+10];

	f(i, 1, n)
	{
		cin>>ar[i];
	}

	int f=0;

	// for(int i=x+1;i<=n-y;i++)
	// {
	// 	f=0;
	// 	for(int j=max(0, i-x);j<i;j++)
	// 	{
	// 		if(ar[i]>ar[j])
	// 		{
	// 			f=1;
	// 			break;
	// 		}
	// 	}
	// 	if(f==1) continue;

	// 	for(int j=i+1;j<=min(n, i+y);j++)
	// 	{
	// 		if(ar[i]>ar[j])
	// 		{
	// 			f=1;
	// 			break;
	// 		}
	// 	}

	// 	if(f==1) continue;

	// 	else 
	// 	{
	// 		cout<<i<<endl;
	// 		break;
	// 	}

	// }

	


	for(int i=1;i<=n;i++)
	{
		f=0;
		for(int j=max(1, i-x);j<i;j++)
		{
			if(i==j) continue;
			if(ar[i]>=ar[j])
			{
				f=1;
				break;
			}
		}
		if(f==1) continue;

		for(int j=i+1;j<=min(n, i+y);j++)
		{
			if(i==j) continue;

			if(ar[i]>=ar[j])
			{
				f=1;
				break;
			}
		}

		if(f==1) continue;

		else 
		{
			cout<<i<<endl;
			break;
		}

	}

	return 0;
}