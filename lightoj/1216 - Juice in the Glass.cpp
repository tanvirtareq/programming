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
		double r1, r2, h, p;

		scanf("%lf%lf%lf%lf", &r1, &r2, &h, &p);

		double x=h*r2/(r1-r2);
		double r=r2*(x+p)/x;

		double ans=(1.0/3.0)*pi*(r*r*(p+x)-r2*r2*x);
		
		printf("%.6lf\n", ans);
	}
	return 0;
}