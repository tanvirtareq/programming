#include<bits/stdc++.h>
#include<cstdio>
typedef long long unsigned llu;
typedef long long int lld;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t, d;
	double x, y, z;
	cin>>t;
	while(t--)
	{
		cin>>d;
		if(d*d<4*d) cout<<"N"<<endl;

		else
		{
			x=d*d-4*d;
			x=sqrt(x)+d;
			x=x/2;
			y=d-x;
			//cout<<"Y"<<" "<<x<<" "<<y<<endl;
			printf("Y %.9lf %.9lf\n", x, y);
		}

	}


	//fclose(stdin);
	//fclose(stdout);

	return 0;
}