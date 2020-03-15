#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;
#define v(a) vector<a>
#define p(a, b) pair<a,b> 

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> pqi;
typedef priority_queue<int , vi, greater<int> > mnpqi;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	int tt=0;
	int ar[n+10];

	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		tt+=ar[i];
	}

	int nd=tt/2+1;

	vi v;

	int st=ar[1];;
	v.push_back(1);

	if(st>=nd)
	{
		cout<<1<<endl<<1<<endl;
		return 0;
	}

	for(int i=2;i<=n;i++)
	{
		if(2*ar[i]<=ar[1]){

			v.push_back(i);
		st+=ar[i];
	}

		if(st>=nd) break;
	}

	if(st>=nd)
	{
		cout<<v.size()<<endl;
		for(int j=0;j<v.size();j++)
		{
			cout<<v[j]<<" ";
		}
	}
	else cout<<0<<endl;



	return 0;
}