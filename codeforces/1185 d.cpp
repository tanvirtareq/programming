#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> pq;



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
	map<int, int> mp;
	for(int i=0;i<v.size();i++)
	{
		int x;
		cin>>x;
		v.pb(x);
		mp[x]=i;
	}

	sort(v.begin(), v.end());

	if(v.size()==2)
	{
		cout<<-1<<endl;
		return 0;
	}

	if(v.size()==3)
	{
		if(v[2]-v[1]==v[1]-v[0])
		{
			cout<<-1<<endl;
			return 0;
		}
		cout<<1<<endl;
		return 0;
	}

	if(v.size()==4)
	{
		int d1=v[1]-v[0];
		int d2=v[2]-v[1];
		int d3=v[3]-v[2];

		if(d1==d2 && d1==d3)
		{
			cout<<-1<<endl;
		}
	}

	return 0;
}

