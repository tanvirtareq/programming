#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(int i=a;i<=b;i++)
#define	mx	1500000
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;

	cin>>t;

	f(i,1, t)
	{
		double a, b;
		char ch;
		cin>>a>>ch>>b;

		double angl=acos((a*a-b*b)/(a*a+b*b));
		double rx=sqrt(a*a+b*b)/2;

		double hfp=rx*angl+a;

		double x=200/hfp;

		cout<<fixed<<setprecision(8);
		cout<<"Case "<<i<<": "<<a*x<<" "<<b*x<<endl;

		
	}



	return 0;
}