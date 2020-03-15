#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string a="abcd";
	for(int i=0;i<n;i++)
	{
		int j=(i%4);
		cout<<a[j];
	}
	cout<<endl;

	return 0;
}