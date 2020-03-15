#include<bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int x=n%4;

	if(x==0)
	{
		cout<<1<<" "<<"A"<<endl;
	}
	if(x==1)
	{
		cout<<0<<" "<<"A"<<endl;
	}
	if(x==2)
	{
		cout<<1<<" "<<"B"<<endl;
	}
	if(x==3)
	{
		cout<<2<<" "<<"A"<<endl;
	}


}