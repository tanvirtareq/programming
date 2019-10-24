#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pi 2*acos(0.0)
#define Mk make_pair
#define Pb push_back
#define sp " "
#define fst first
#define snd second
int i,j,k;
int fr[]={0,0,1,-1,-1,1,-1,1};
int fc[]={-1,1,0,0,1,1,-1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	int tc,n,x,y,nums=0;
	cin>>tc;
	for(i=1 ; i<=tc ; i++)
	{
		nums = 0;
		map< int , int > m;
		cin>>n;
		for(j=1 ; j<=n ; j++)
		{
			cin>>x>>y;
			m[y] += x;
			nums+=x;
		}
		int sum=0,mx=0 ;
		map< int , int >::iterator it;
		map< int , int >::iterator it2;
		it = m.begin();
		for( ; it != m.end() ; it++)
		{
			sum = nums*it->fst ;
			mx = max(sum,mx);
			nums -= it->second;
		}
		cout<<"Case "<<i<<": "<<mx<<endl;
	}

	return 0;
}
