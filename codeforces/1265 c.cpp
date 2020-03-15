#include<bits/stdc++.h>

using namespace std;

// int posi(int md)
// {
// 	int ct=0;
// 	int i=0;
// 	for(;i<v.size();i++)
// 	{
// 		ct+=v[i];
// 		if(ct>md)
// 		{
// 			g=ct-v[i];
// 			ct=0;
// 			i--;
// 			break;
// 		}
// 	}

// 	for(;i<v.size();i++)
// 	{
// 		ct+=v[i]
// 		if(ct>md)
// 		{
// 			s=ct;
// 			ct=0;
// 			break;
// 		}
// 	}

// 	for(;i<v.size();i++)
// 	{
// 		ct+=v[i];
// 		if(ct>md)
// 		{
// 			b=ct;
// 			ct=0;
// 			break;
// 		}
// 	}
// }

// int bs(int st, int ed)
// {
// 	if(st>ed) return 0;
// 	if(st==ed)
// 	{
// 		if(posi(st)) return st;
// 		else return 0;
// 	} 
// 	int md=(st+ed)/2;

// 	if(posi(md)) return bs(md, ed);
// 	else return bs(st, md-1);

// }

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a;

	cin>>a;
	while(a--)
	{
		int n;
		cin>>n;
		// cout<<n<<endl;

		int y;
		cin>>y;
		int lst=y;
		vector<int> v;
		int ct=1;
		for(int i=2;i<=n;i++)
		{
			cin>>y;
			if(y==lst) ct++;
			else 
			{
				v.push_back(ct);
				ct=1;
				lst=y;
			}

		}
		v.push_back(ct);

		int g=v[0];

		// for(int i=0;i<v.size();i++) cout<<v[i]<<endl;

		ct=0;
		int i=1;
		int s=0;
		for(;i<v.size();i++)
		{
			ct+=v[i];
			if(ct>g)
			{
				s=ct;
				ct=0;
				break;
			}
		}

		int ctx=g+s;
		// cout<<ctx<<endl;
		// cout<<i<<endl;
		i++;
		if(g==0 or s==0 or i>=v.size()) 
		{
			cout<<"0 0 0"<<endl;
			continue;
		}
		int f=0;
		for(;i<v.size();i++)
		{
			ctx+=v[i];
			ct+=v[i];
			if(ctx>n/2)
			{
				f=1;
				ct-=v[i];
				// cout<<ctx<<" "<<n/2<<endl;
				if(ct>g)
				{
					cout<<g<<" "<<s<<" "<<ct<<endl;
				}

				else cout<<0<<" "<<0<<" "<<0<<endl;

				break;
			}

		}
		if(f==0)
		{
			cout<<0<<" "<<0<<" "<<0<<endl;
		}
	}

	return 0;
}