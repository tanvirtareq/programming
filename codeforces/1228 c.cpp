#include<bits/stdc++.h>

#define dbg(a) cout<<#a<<" "<<a<<endl
#define pb push_back
#define mk make_pair
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;

lu x, n, csum[100], ans=1;
vector<lu> v;

lu power(lu b, lu p)
{
	if(p==0) return 1;
	if(p==1) return b%md;

	lu x=power(b, p/2)%md;
	x=(x*x)%md;
	if(p&1ULL) x=(x*b)%md;
	return x;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin>>x>>n;

	lu fc=x;

	for(lu i=2;i*i<=fc;i++)
	{
		if(fc%i==0)
		{
			v.push_back(i);
			while(fc%i==0) fc=fc/i;
		}
	}


	if(fc!=1) v.push_back(fc);

	for(int i=0;i<v.size();i++)
	{
		lu p=v[i];

		lu p1=p;
		lu n1=n;

		while(p<=n1)
		{
			ans=(ans*power(p, n1/p))%md;
			n1=n1/p;
		}

		
}

	cout<<ans<<endl;
	
	return 0;
}