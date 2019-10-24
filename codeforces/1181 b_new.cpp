#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

string fn(string s, int x)
{
	string a, b, c;

	a.assign(s.begin(), s.begin()+x+1);
	b.assign(s.begin()+x+1, s.end());
	// cout<<x<<endl;

	// cout<<a<<" "<<b<<endl;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int cr=0, i=0, j=0;

	while(i<a.size() && j<b.size())
	{
		int tmp=a[i]-'0'+b[j]-'0'+cr;
		c.push_back(tmp%10+'0');
		cr=tmp/10;
		i++;
		j++;
	}


	while(i<a.size())
	{
		int tmp=a[i]-'0'+cr;
		c.push_back(tmp%10+'0');
		cr=tmp/10;
		i++;
		
	}


	while(j<b.size())
	{
		int tmp=b[j]-'0'+cr;
		c.push_back(tmp%10+'0');
		cr=tmp/10;
		
		j++;
	}
	while(cr>0)
	{
		c.push_back(cr%10+'0');
		cr=cr/10;
	}

	reverse(c.begin(), c.end());

	return c;

}

string mn(string x, string y)
{

	if(x.size()<y.size()) return x;
	if(x.size()>y.size()) return y;

	for(int i=0;i<x.size();i++)
	{
		if(x[i]<y[i]) return x;
		if(x[i]>y[i]) return y;
	}
	return x;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
	cin>>l;
	string x;
	cin>>x;

	// fn(x, 3);


	int ct=LONG_MAX;

	if(x[1]!='0') ct=min(ct,  max(1, l-1));

	for(int i=1;i<x.size()-1;i++)
	{
		// cout<<i<<endl;
		if(x[i+1]!='0')
		{
			// cout<<0<<" "<<i<<" "<<i+1<<" "<<l-1<<endl;
			ct=min(ct, max(i+1,l-i-1));
			// cout<<ct<<endl;

		}
	}
	int bt=ct;



	int f=0;

	
	 ct=LONG_MAX;

	string an;

	if(x[1]!='0') ct=min(ct,  max(0+1, l-1));

	if(bt==ct)
	{
		if(f==0)
		{
			f=1;
			string ana=fn(x, 0);
			an=ana;

		}
	}

	for(int i=1;i<x.size()-1;i++)
	{
		if(x[i+1]!='0')
		{
			ct=max(i+1,l-i-1);
			// cout<<ct<<" "<<bt<<endl;
			if(bt==ct)
			{
				if(f==0)
				{
					f=1;
					string ana=fn(x, i);
					an=ana;

				}
				else 
				{
					an=mn(an, fn(x, i));
				}
			}
		}
	}

	cout<<an<<endl;

	return 0;
}