#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define pb(a) push_back(a)

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

	vi v;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.pb(x);
	}

	int f=0;

	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i-1]>v[i] && v[i+1]>v[i]) 
		{
			f=1;
			break;
		}
	}

	(f)? cout<<"NO"<<endl: cout<<"YES"<<endl;


	return 0;
}