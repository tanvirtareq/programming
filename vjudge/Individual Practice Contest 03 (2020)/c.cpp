#include<bits/stdc++.h>
#define ii pair<ll, ll> 
#define ll long long
#define llu long long unsigned

using namespace std;

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


ll find(ll a, ll b, ll c, ll & x, ll & y)
{
    ll g=gcd(a,b, x, y);
    x=x*c/g;
    y=y*c/g;
    return g;
}

int main()
{
	ll n;
	while(cin>>n)
	{
		if(n==0) break;
		ll c1, n1, c2, n2;
		cin>>c1>>n1>>c2>>n2;

		ll x, y;

		ll g=find(n1,n2, n, x, y);
		if(n%g!=0)
		{
			cout<< "failed"<<endl;
			continue;
		}
		ll t=floor((double)x*g/(double)n2);
	
		// t+=100000;

		// if(x>0)
		// {
			x=x-n2*t/g;
			y=y+n1*t/g;	
		// }
		long long unsigned mn=10000000000000000000ULL;
		ll xm, ym;
		xm=ym=-1;
		while(y>=0)
		{
			long long unsigned fl=(llu)c1*x+(llu)c2*y;
			if(fl<mn)
			{
				mn=fl;
				xm=x;
				ym=y;
			}
			x+=n2/g;
			y-=n1/g;

		}

		if(xm==-1)
		{
			cout<< "failed"<<endl;
		}
		else 
			cout<<xm<<" "<<ym<<endl;


	}


	
	return 0;
}