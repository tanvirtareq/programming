#include<bits/stdc++.h>
#include<cstdio>
typedef long long unsigned llu;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{

		string x;
		cin>>x;
		if(x.size()<=10) cout<<x<<endl;
		else
		{
			cout<<x[0]<<x.size()-2<<x[x.size()-1]<<endl;
		}
	}


	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
