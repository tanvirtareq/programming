#include<bits/stdc++.h>
#define ll long long

using namespace std;
#define pi  3.14159265358979323846

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		double d, abd;
		cin>>d>>abd;
		abd=(abd*pi)/180.0;
		double x=d/tan(abd);
		// cout<<x<<endl;
		double h_x=d/sin(abd);
		// cout<<h_x<<endl;
		double h=h_x+x;;
		printf("%.4lf\n", h);
	}

	return 0;
}