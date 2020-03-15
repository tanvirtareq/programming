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
	while(q--)
	{
		int n, m;
		cin>>n>>m;
		int ar[n+10];
		int cst=0;
		for(int i=1;i<=n;i++) 
			{
				cin>>ar[i];
				cst+=2*ar[i];
			}
		if(n>m or n==2)
		{
			cout<<-1<<endl;
			continue;
		}


		vector<pair<int, pair<int, int> > > v;

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				v.push_back({ar[i]+ar[j],{i, j} });
			}
		}

		sort(v.begin(), v.end());

		for(int i=0, j=1;i<v.size(),  j<=m-n;i++)
		{
			pair<int, pair<int, int> > p=v[i];
			if(abs(p.second.first-p.second.second)==1) continue;
			if(abs(p.second.first-p.second.second)==n-1) continue;

			cst+=p.first;
			j++;
		}

		cout<<cst<<endl;

		for(int i=1;i<n;i++)
		{
			cout<<i<<" "<<i+1<<endl;
		}
		cout<<1<<" "<<n<<endl;

		for(int i=0, j=1;i<v.size(),  j<=m-n;i++)
		{
			pair<int, pair<int, int> > p=v[i];
			if(abs(p.second.first-p.second.second)==1) continue;
			if(abs(p.second.first-p.second.second)==n-1) continue;

			cout<<p.second.first<<" "<<p.second.second<<endl;
		}

	}

	return 0;
}