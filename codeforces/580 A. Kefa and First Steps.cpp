#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long unsigned llu;

using namespace std;

string tolowerstring(string x)
{
	for(int i=0;i<x.size();i++)
		x[i]=tolower(x[i]);

	return x;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	int x, p, max=1, c=1;
	cin>>p;
	n--;
	while(n--)
	{
		cin>>x;
		//cout<<p<<"  "<<x<<endl;
		if(x<p)
		{
			if(max<c) max=c;

			c=1;
		}
		else c++;

		p=x;

	}
	if(max<c) max=c;
	cout<<max<<endl;

	return 0;
}
