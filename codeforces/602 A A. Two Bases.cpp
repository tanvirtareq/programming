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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	lld n1, b1, n2, b2, temp1, temp2;

	lld x=0, y=0;

	cin>>n1>>b1;
	char ar1[15], ar2[15];
	while(n1--)
	{
		cin>>temp1;
		//cout<<temp1<<" "<<n1<<endl;
		x+=temp1*power(b1, n1);
		//cout<<x<<"  "<<endl;
	}
	//cout<<x<<endl;

	cin>>n2>>b2;
	temp2=n2;
	while(n2--)
	{
		cin>>temp1;
		y+=temp1*power(b2, n2);
	}

	//cout<<y<<endl;


	if(x==y) cout<<"="<<endl;
	if(x<y) cout<<"<"<<endl;
	if(x>y) cout<<">"<<endl;


	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
