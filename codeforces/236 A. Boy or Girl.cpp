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

	set<char>mp;
	char ch;

	while(cin>>ch)
	{
		mp.insert(ch);
	}

	if(mp.size()%2!=0) cout<< "IGNORE HIM!"<<endl;

	else cout<< "CHAT WITH HER!" <<endl;
	return 0;
}
