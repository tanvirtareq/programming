#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

lu   n, a[7100], b[7100], ans, vis[7100];
vector<lu>v;
map<lu, lu> mp;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n;

	for(lu   i=1;i<=n;i++)
	{
		cin>>a[i];
		if(mp[a[i]]==1) v.push_back(a[i]);

		mp[a[i]]++;
	}

	for(lu   i=1;i<=n;i++) cin>>b[i];

	for(lu   i=0;i<v.size();i++)
	{
		// cout<<v[i]<<endl;
		for(lu   j=1;j<=n;j++)
		{
			if(vis[j]==0 and (a[j]|v[i])==v[i])
			{
				 ans+=b[j];
				 vis[j]=1;
			}
			// else cout<<j<<"  "<<a[j]<<endl;

			
		}
	}

	cout<<ans<<endl;

	return 0;
}