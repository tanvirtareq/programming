#include<bits/stdc++.h>
#include<cstdio>
typedef long long unsigned llu;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m,n,a;
	cin>>m>>n>>a;

	llu ans=(llu)ceil((double)m/a)*ceil((double)n/a);
	//ans=ceil(m/a);
	cout<<ans<<endl;

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
