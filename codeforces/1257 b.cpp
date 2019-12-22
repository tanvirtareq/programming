#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define xd 101000

using namespace std;
typedef long long ll;

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<int, pair<int,int> > mp;
		int mn=INT_MAX;

		for(int i=1;i<=n;i++)
		{

			int x;
			cin>>x;
			// dbg(i);
			// dbg(mn);
			// dbg(x);
			// dbg(mp[x].first);

			if(mp[x].first==0)
			{
				mp[x].first=i;
				mp[x].second=INT_MAX;
			}

			else
			{
				
				mp[x].second=i-mp[x].first+1;
				mn=min(mn, mp[x].second);
				// dbg(mn);
				mp[x].first=i;;
			}
			// dbg(x);
			// dbg(mp[x].first);

		}
		if(mn==INT_MAX)
			cout<<-1<<endl;
		else cout<<mn<<endl;
	}
	
	return 0;
}
