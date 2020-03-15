#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	#endif

	int q;
	cin>>q;
	while(q--)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;

		if(min(d/c, a)*c+b>=d)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}

	return 0;
}