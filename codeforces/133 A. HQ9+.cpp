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
	while(cin>>ch)
	{
		if(ch=='H'||
			ch=='Q'||
			ch=='9') flag='1';
	}
	//cout<<flag<<endl;
	if(flag=='1') cout<<"YES";
	else cout<<"NO";

	return 0;
}
