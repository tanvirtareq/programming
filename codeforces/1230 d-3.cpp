#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair

#define memo(a, n, i) (for(lu i=0;i<=n;i++) a[i]=i)

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

lu n;
vector<pair<lu,lu> > v;

lu chk(lu nm)
{
	set<int> s;

	for(lu i=0;i<60;i++)
	{
		if((v[nm].first&(1ULL<<i))==0) continue;
		for(lu j=0;j<v.size();j++)
		{
			if((v[j].first&(1ULL<<i))==0){
			 s.insert(j);
			}
		}
	}
	if(s.size()==v.size()-1) return 1;
	return 0;
}

lu rc()
{

	for(lu i=0;i<v.size();i++)
	{
		if(chk(i))
		{
			v.erase(v.begin()+i);
			rc();
		}
	}
}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>n;
	for(lu i=0;i<n;i++)
	{
		lu x;
		cin>>x;
		v.pb(mk(x, 0));
	}
	

	for(lu i=0;i<n;i++)
	{
		lu x;
		cin>>x;
		v[i].second=x;
	}

	for(lu i=0;i<v.size();i++)
	{
		if(chk(i))
		{
			v.erase(v.begin()+i);
			rc();
		}
	}

	if(v.size()==1)
	{
		cout<<0<<endl;
		return 0;
	}


	lu sm=0;

	for(lu i=0;i<v.size();i++) sm+=v[i].second;

	cout<<sm<<endl;

	
	return 0;
}