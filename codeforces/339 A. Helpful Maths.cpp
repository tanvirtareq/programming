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

	int ar[110];

	int x, i=0;
	while(cin>>x)
	{
		ar[i]=x;
		i++;
	}
	i--;
	sort(ar, ar+i+1);

	cout<<ar[0];
	for(int j=1;j<=i;j++)
		cout<<"+"<<ar[j];

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
