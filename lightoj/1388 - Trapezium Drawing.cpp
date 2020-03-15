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

struct  pt
{
	double x, y;
	pt(double a, double b)
	{
		x=a;
		y=b;
	}

	pt operator + (const pt &p) const
	{
		return pt(x+p.x, y+p.y);
	}

	pt operator - (const pt &p ) const
	{
		return pt(x-p.x, y-p.y);
	}

	pt operator * (double d) const
	{
		return pt(x*d, y*d);
	}
	pt operator / (double d) const
	{
		return pt(x/d, y/d);
	}
};

double ax, ay, bx, by, b, c, d;


double abs(pt A)
{
	return sqrt(A.x*A.x+A.y*A.y);
}

pt unitVector(pt A)
{
	return A/abs(A);
}

pt PointAlongLine(pt A, pt B, double d)
{
	return A+unitVector(B-A)*d;
}

double dist2D(pt A, pt B)
{
	return abs(B-A);
}

pt PointParralelToVector(pt A, pt B, double d)
{
	return A+unitVector(B)*d;
}

pt RotateCCW(pt p, double theta)
{
    return pt(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
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
	scanf("%d", &t);
	double pi=2*acos(0.0);
	for(int in=1;in<=t;in++)
	{
		printf("Case %d:\n", in);
		scanf("%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &b, &c, &d);

		pt A=pt(ax, ay);
		pt B=pt(bx, by);

		pt cntr=PointAlongLine(A, B, c);

		double ds=dist2D(cntr, B);
		// when cntr is bitween A, and B
		double angl=acos((ds*ds+d*d-b*b)/(2*ds*d));
		pt C=PointParralelToVector(cntr, RotateCCW(B-cntr, angl), d);

		pt D=PointParralelToVector(C, A-B, c);

		//what happend when B is between A and cntr

		printf("%.6lf %.6lf %.6lf %.6lf\n", C.x, C.y, D.x, D.y);
	}
	return 0;
}
