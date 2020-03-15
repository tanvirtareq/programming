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

	char ch, flag='0';
	int c=0;
	while(cin>>ch)
	{
		if(ch=='4'||
			ch=='7') c++;
	}
	//cout<<flag<<endl;
	if(c==4||
		c==7||
		c==47||
		c==74) cout<<"YES";
	else cout<<"NO";

	return 0;
}
