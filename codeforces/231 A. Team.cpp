#include<bits/stdc++.h>
#include<cstdio>
typedef long long unsigned llu;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, c=0;
	cin>>n;
	while(n--)
	{
		int x=0;
		int y;
		int t=3;
		while(t--)
		{
			cin>>y;
			x=x+y;
		}
		if(x>=2) c++;
	}
	cout<<c<<endl;


	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
