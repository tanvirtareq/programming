#include<bits/stdc++.h>

using namespace std;

double ar[10000000];

int main()
{
	int t;
	cin>>t;

	

	ar[1]=1.0;
	for(int i=2;i<10000000;i++)
	{
		double y=1.0/2.0;
		ar[i]=ar[i-1]+(1.0/(double)i);
		// cout<<ar[i]<<endl;
	}

	while(t--)
	{
		int n;
		cin>>n;
		cout<<fixed<<setprecision(6);
		cout<<ar[n]<<endl;
	}

	return 0;
}