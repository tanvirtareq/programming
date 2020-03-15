#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned
#define ii pair<int, int>
#define iii pair<int, ii> 

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	#endif

	int n, a, b, c;
	cin>>n;
	int br[n+10]={0}, ans[n+10];
	vector<int> v[n+10], v2[n+10];
	for(int i=1;i<=n-2;i++)
	{
		cin>>a>>b>>c;
		v[a].push_back(i);
		v[b].push_back(i);
		v[c].push_back(i);
		v2[i].push_back(a);
		v2[i].push_back(b);
		v2[i].push_back(c);

	}
	int ind=0;
	int ind2=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==1)
		{
			if(ind!=0)
			{

				ans[n]=i;
				ind2=v[i][0];
				break;
			}
			ans[1]=i;
			ind=v[i][0];
		}
	}
	int p1=v2[ind][0];
	int p2=v2[ind][1];
	int p3=v2[ind][2];

	ans[v[p1].size()]=p1;
	ans[v[p2].size()]=p2;
	ans[v[p3].size()]=p3;

	p1=v2[ind2][0];
	p2=v2[ind2][1];
	p3=v2[ind2][2];

	ans[n-v[p1].size()+1]=p1;
	ans[n-v[p2].size()+1]=p2;
	ans[n-v[p3].size()+1]=p3;

	for(int i=4;i<=n-3;i++)
	{
		p1=ans[i-3];
		p2=ans[i-2];
		p3=ans[i-1];

		map<int, int> mp;
		map<int, int>::iterator it;

		for(int j=0;j<v[p1].size();j++)
			mp[v[p1][j]]++;

		for(int j=0;j<v[p2].size();j++)
			mp[v[p2][j]]++;

		for(int j=0;j<v[p3].size();j++)
			mp[v[p3][j]]++;


		for(it=mp.begin();it!=mp.end();it++)
		{
			// cout<<it->first<<" "<<it->second<<endl;
			if(it->second==2)
			{
				ind=it->first;
				int flg=0;

				for(int j=0;j<v2[ind].size();j++)
				{
					if(v2[ind][j]==p1)
					{
						flg=1;
						break;
					}
				}
				if(flg) continue;
				else break;
				// cout<<it
			}
		}
		// cout<<ind<<endl;

		for(int j=0;j<v2[ind].size();j++)
		{
			// cout<<v2[ind][j]<<endl;
			if(v2[ind][j]!=p1 and
				v2[ind][j]!=p2 and
				v2[ind][j]!=p3
				){
			ans[i]=v2[ind][j];
			break;
			}
		}

	}

	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";


	return 0;
}