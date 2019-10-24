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

	int n,m;
	cin>>n>>m;

	
	pq p;

	int xd=0;
	f(i, n)
	{
		int x;
		cin>>x;
		
		int rm=xd;
		
		int ct=0;
		int c=0;
		vi v;
		while(!p.empty())
		{
			if(xd+x<=m) break; 
			ct+=p.top();
			xd-=p.top();
			c++;
			v.pb(p.top());
			p.pop();
			// if(ct>x) break;
			
		}
		for(int j=0;j<v.size();j++)
		{
			p.push(v[j]);
			xd+=v[j];
		}

		cout<<c<<" ";
		p.push(x);
		xd+=x;
		
	}


	return 0;
}

