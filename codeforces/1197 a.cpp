#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	while(n--)
	{
		int m;
		cin>>m;
		vi v;
		for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		reverse(v.begin(), v.end());


		int r=v[1]-1;
		// cout<<v[1]<<endl;

		int c=0;

		for(int i=2;i<v.size();i++)
		{
			if(v[i]>0) c++;
		}

		cout<<min(r, c)<<endl;

	}


	return 0;
}