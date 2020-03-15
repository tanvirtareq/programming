#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

#define memo(a, n, i) (for(int i=0;i<=n;i++) a[i]=i)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

lu n;
vector<pair<lu,lu> > v;
int s;
map<lu, int> mp;

int rc(lu in)
{
	int ct=0;
	int indx=-1;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].first&(1ULL<<in))
		{
			ct++;
			indx=i;
		}
	}
	if(ct==1)
	{
		if(v[indx].second*2>=s)
		{
			cout<<v[indx].second<<endl;
			return 1;
		}

		s=s-v[indx].second;

		// cout<<s<<"  "<<v[indx].first<<endl;

		v.erase(v.begin()+indx);

		for(int i=0;i<v.size();i++)
		{
			if(rc(i)) return 1;
		}
	}


	return 0;


}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n;
	for(int i=0;i<n;i++)
	{
		lu x;
		cin>>x;
		// if(mp[x]==0)
		v.pb(mk(x, 0));

		// mp[x]++;
	}
	

	for(int i=0;i<n;i++)
	{
		lu x;
		cin>>x;
		v[i].second=x;
		s+=x;
	}

	for(int i=0;i<60;i++)
	{
		if(rc(i))
		{
			return 0;
		}
	}

	int sm=0;

	for(int i=0;i<v.size();i++) sm+=v[i].second;

	cout<<sm<<endl;

	
	return 0;
}