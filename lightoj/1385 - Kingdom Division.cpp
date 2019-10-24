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
	// dbg(t);
	for(int in=1;in<=t;in++)
	{
		printf("Case %d: ", in);
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		// a+=eps;
		// b+=eps;
		// c+=eps;
		double an=a*c/b;

		double d1=a+an;
		double d2=an+c;
		double d3=a+b;
		if(abs(b-0.0)<=eps)
		{
			printf("-1\n");
			continue;
		}
		// if(abs(a-0.0)<=eps || abs(c-0.0)<=eps)
		// {
		// 	printf("0.000000\n");
		// 	continue;
		// }

		if(abs(d3-d1)<=eps)
		{
			printf("-1\n");
			continue;
		}

		double x=d1*d2/(d3-d1);

		if(x+an<0)
		{
			printf("-1\n");
			continue;
		}

		printf("%.6lf\n", an+x);
	}
	return 0;
}