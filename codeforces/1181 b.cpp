#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int chk(char ar[], int i, int j)
{


}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;

	char ar[l+10];

	for(int i=1;i<=l;i++)
	{
		cin>>ar[i];

	}

	int f1=l/2;
	int f2=ceil(l/2.0);

	if(ar[f1]==0 && ar[f2]!=0)
	{
		fn(ar, f2);
	}

	if(ar[f1]!=0 && ar[f2]==0)
	{
		fn(ar, f1);
	}

	if(ar[f1]==0 && ar[f2]==0)
	{
		while(ar[f1]!=0 || ar[f2]!=0)
		{
			if(f1>2) f1--;
			if(f2<n-1) f2++;
		}

		if(ar[f1]==0 && ar[f2]!=0)
		{
			fn(ar, f2);
		}

		if(ar[f1]!=0 && ar[f2]==0)
		{
			fn(ar, f1);
		}

		if(ar[f1]!=0 && ar[f2]!=0)

		{
			if(ar[f1]!=ar[f2])
			{
				ar[f1]>ar[f2]? fn()

			}

			for(int i=1, int j=f1; j<n-1;i++, j++)
			{
				if(chk(ar, i, j))
				{
					fn(ar, chk(ar, i, j));
				}
			}
		}
	}

	if(ar[f1]!=0 && ar[f2]!=0)

	{


		for(int i=1, int j=f1; j<n-1;i++, j++)
		{
			if(chk(ar, i, j))
			{
				fn(ar, chk(ar, i, j));
			}
		}
	}

	return 0;
}