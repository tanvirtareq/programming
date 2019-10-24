#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<int, int> ii;



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin>>n>>k;

	vi v;

	for(int i=0;i<v.size();i++)
	{
		int x;
		cin>>x;
		v.pb(x);
	}


	vector<ii> vn;



	for(int i=1;i<n;i++)
	{
		int x=v[i]-v[i-1];
		dbg;

		vn.pb(make_pair(x, i));

	}
	dbg;

	sort(vn.begin(), vn.end());

	int nsd[n+10]={0};
	int ct=0;

	for(int i=vn.size()-1;i>=0 && ct<=k ;i--)
	{
		ii fsd=vn[i];
		nsd[fsd.second]=1;
		ct++;
	}

	int ans=0;

	int i=0;

	for(int j=0;j<n;j++)
	{
		if(nsd[j]==1)
		{
			ans+=v[j-1]-v[i];
			i=j;
		}
	}
	cout<<ans<<endl;


	return 0;
}