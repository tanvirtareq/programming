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

	int ar[10];
	int s=0;


	for(int i=0;i<4;i++){
		cin>>ar[i];
		s+=ar[i];
	}
	if(s%2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	s=s/2;

	// sort(ar, ar+4);

	if(ar[0]==s || ar[1]==s || ar[2]==s || ar[3]==s)
	{
		cout<<"YES"<<endl;
		return 0;
	}

	int x=0;

	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(ar[i]+ar[j]==s)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			for(int k=j+1;k<4;k++)
			{
				if(ar[i]+ar[j]+ar[k]==s)
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}

	cout<<"NO"<<endl;


	
	return 0;
}