#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	#endif

	int q;
	cin>>q;
	while(q--)
	{
		// cout<<q<<endl;
		int a, b, c, d;
		cin>>a>>b;
		d=abs(a-b);
		int ct=0;
		while(d!=0)
		{
			if(d>=5)
			{
				if(d%5>2)
				{
					ct+=d/5+1;
					d=abs(d-(d/5+1)*5);
				}
				else
				{
					ct+=d/5;
					d=abs(d-(d/5)*5);
				}
			}
			else if(d>=2)
			{
				ct+=d/2;
				d=abs(d-(d/2)*2);
			}
			else 
			{
				ct++;
				d--;
			}

		}
		cout<<ct<<endl;
	}

	return 0;
}