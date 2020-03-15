#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;



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
	double pi=2.0*acos(0.0);
	for(int in=1;in<=t;in++)
	{
		printf("Case %d: ", in);
		double r1, r2, r3;
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		double a=r1+r2;
		double b=r1+r3;
		double c=r2+r3;
		double s=(a+b+c)/2.0;
		double At=sqrt(s*(s-a)*(s-b)*(s-c));

		double A=acos((b*b+c*c-a*a)/(2*b*c));
		double B=acos((a*a+c*c-b*b)/(2*a*c));
		double C=acos((a*a+b*b-c*c)/(2*a*b));

		double ar=0.5*(r3*r3*A+r2*r2*B+r1*r1*C);

		printf("%.6lf\n", At-ar);
	}
	return 0;
}