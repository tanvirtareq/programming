#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--)
	{
		int a, b, c;
		cin>>a>>b>>c;

		cout<<a-min(b, c)+1<<endl;

	}

	return 0;
}