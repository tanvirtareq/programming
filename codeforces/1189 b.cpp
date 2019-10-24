#include<bits/stdc++.h>
#define f(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a) 

using namespace std;

typedef vector<int> vi;

int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin>>n;

	vi v;

	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v.pb(x);
	}
	// cout<<v.size()<<endl;


	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	// for(int i=0;i<v.size();i++)
	// {
	// 	cout<<v[i]<<" ";
	// }
	// 	cout<<endl;

	vi an;

	for(int i=0;i<v.size();i+=2)
	{
		an.pb(v[i]);
	}

	for(int i=1;i<v.size();i+=2)
	{
		an.pb(v[i]);
	}

	reverse(an.begin()+ceil(an.size()/2.0), an.end());

	// for(int i=0;i<an.size();i++)
	// {
	// 	cout<<an[i]<<" ";
	// }
	// 	cout<<endl;

	int fl=0;

	for(int i=0;i<an.size();i++)
	{
		if(an[i]>=an[(i-1+n)%n]+an[(i+1+n)%n]) 
		{
			fl=1;
		}
	}

	

	if(fl==1) cout<<"NO"<<endl;

	else 
	{
		cout<<"YES"<<endl;
		for(int i=0;i<an.size();i++)
	{
		cout<<an[i]<<" ";
	}
		cout<<endl;
	}

	return 0;
}