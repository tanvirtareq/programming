#include<bits/stdc++.h>

using namespace std;

int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin>>n;

	string x;
	cin>>x;

	if(n==1)
	{
		cout<<1<<endl;
		cout<<x<<endl;
		return 0;
	}

	int ct=0;
	for(int i=0;i<x.size();i++)
	{
		ct+=x[i]-'0';
	}

	if(ct*2!=n)
	{
		cout<<1<<endl;
		cout<<x<<endl;
	}

	else 
	{
		char c=x[0];
		x.erase(x.begin());
		cout<<2<<endl;
		cout<<c<<" "<<x<<endl;
	}
	return 0;
}