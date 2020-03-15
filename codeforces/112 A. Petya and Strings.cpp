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

	string a, b;
	cin>>a>>b;

	a=tolowerstring(a);
	b=tolowerstring(b);

	if(a<b) cout<<-1<<endl;
	else if(a>b) cout<<1<<endl;
	else cout<<0<<endl;

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
