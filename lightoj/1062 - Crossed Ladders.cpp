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

double x, y, c;

double fc(double d)
{
	return d/c+d/(sqrt(y*y-d*d))-d/sqrt(x*x-d*d);
}
double fc1(double d)
{
	return c/sqrt(x*x-d*d)+c/sqrt(y*y-d*d)-1;
}

double bns(double l, double r)
{
	int it=100000;
	while(it--)
	{
		double m=(l+r)/2.0;
		double xr=fc1(m);
		if(xr==0) return m;
		if(xr<0) l=m;
		else r=m;
	}
	return l;

}

int main()
{
	int t;

	scanf("%d", &t);
	for(int in=1;in<=t;in++)
	{
		printf("Case %d: ", in);

		scanf("%lf%lf%lf", &x, &y, &c);

		double ans=bns(0, min(x ,y));
		printf("%.10lf\n", ans);
	}
	return 0;
}
