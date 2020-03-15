#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define dbg(a) cout<<#a<<"= "<<a<<endl;
#define eps 1e-17

using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct PT{
	long double x, y;
	PT(){}
	PT(long double x,long double y) :x(x), y(y){}

	PT operator - (PT b)
	{
		return PT(x-b.x, y-b.y);
	}

};

long double dot(PT a, PT b)
{
	return a.x*b.x+a.y*b.y;
}

long double abs(PT a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

int main()
{

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	// scanf("%d", &t);
	cin>>t;
	long double pi=2*acos(0.0);
	for(int in=1;in<=t;in++)
	{
		printf("Case %d: ", in);
		PT o, a, b;
		// scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &o.x, &o.y, &a.x, &a.y, &b.x, &b.y);
		// cin>>o.x>>o.y>>a.x>>a.y>>b.x>>b.x;
		long double i1, i2, i3, i4, i5,i6;
		cin>>i1>>i2>>i3>>i4>>i5>>i6;
		// cout<<i1<<endl;
		// cout<<o.x<<endl;
		o=PT(i1, i2);
		a=PT(i3, i4);
		b=PT(i5, i6);
		// cout<<o.x<<endl;
		long double theta=acos(dot(a-o, b-o)/(abs(a-o)*abs(b-o)));
		long double s=abs(a-o)*theta;
		cout<<fixed<<setprecision(6);
		cout<<s<<endl;
		// printf("%.6Lf\n", s);
	}
	return 0;
}
