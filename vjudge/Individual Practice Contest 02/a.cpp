#include<bits/stdc++.h>
#define ii pair<int, int> 

using namespace std;


int main()
{
	int n;
	map<ii, int> mp;

	cin>>n;
	int mx=0;
	while(n--)
	{
		int x, y;
		cin>>x>>y;

		mp[make_pair(x, y)]++;
		mx=max(mx, mp[make_pair(x, y)]);

	}
	cout<<mx<<endl;
	

	return 0;
}