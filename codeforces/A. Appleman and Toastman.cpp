#include<bits/stdc++.h>
#include<cstdio>
typedef long long unsigned llu;
typedef long long int lld;

using namespace std;

lld power(int b, int p)
{
	//cout<<b<<" "<<p<<endl;
	if(p==1) return (lld)b;
	if(p==0) return (lld)1;

	if(p%2==0)
	{
		lld temp=power(b, p/2);
		//cout<<temp*temp<<endl;
		return temp*temp;
	}

	if(p%2==1)
	{
		lld temp=power(b, p/2);
		//cout<<temp*temp*b<<endl;
		return temp*temp*b;
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n, max1=0,max2=0, c;

	cin>>n;
	int tot=0;
	int t=n;

	while(n--)
	{
		cin>>c;
		tot+=c;
		if(max1<c)
		{
			max2=max1;
			max1=c;
		}
		else if(max2<c)
		{
			max2=c;
		}
	}

	cout<<(t-2)*tot+max1+max2<<endl;


	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
