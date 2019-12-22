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

	// int dp[]

	while(q--)
	{
		int n;
		cin>>n;
		// set<int> s;
		// s.insert(s);
		vector<int> v;
		v.push_back(0);

		for(int i=1;i*i<=n;i++)
		{
			v.push_back(i);
			if(i!=n/i) v.push_back(n/i);

		}
		sort(v.begin(), v.end());
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;

	}

	return 0;
}