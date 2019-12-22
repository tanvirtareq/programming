#include<bits/stdc++.h>

using namespace std;

int A(int a, int b, int c, int d)
{
	if(b>=a)
	{
		b=b-a;
		if(c>b)
		{
			c=c-b-1;
			if(c==d) return 1;
			if(d-c==1) return 1;
		}
	}
	return 0;
}

int B(int a, int b, int c, int d)
{
	if(b>a)
	{
		b=b-a-1;
		if(c>b)
		{
			c=c-b-1;
			if(c==d) return 1;
			if(d-c==1) return 1;
		}
	}
	return 0;
}

void p1(int a, int b, int c, int d)
{
	for(int i=1;i<=a;i++)
	{
		b--;
		cout<<"0 1 ";
	}

	cout<<"2 ";
	c--;
	for(int i=1;i<=b;i++)
	{
		c--;
		cout<<"1 2 ";
	}
	if(d==c)
	{
		for(int i=1;i<=d;i++)
		{
			cout<<"3 2 ";
		}
	}
	else
	{
		cout<<"3 ";
		for(int i=1;i<=c;i++)
			cout<<"2 3 ";
	}

}

void p3(int a, int b, int c, int d)
{
	for(int i=1;i<=a;i++)
	{
		b--;
		cout<<"3 2 ";
	}

	cout<<"1 ";
	c--;
	for(int i=1;i<=b;i++)
	{
		c--;
		cout<<"2 1 ";
	}
	if(d==c)
	{
		for(int i=1;i<=d;i++)
		{
			cout<<"0 1 ";
		}
	}
	else
	{
		cout<<"0 ";
		for(int i=1;i<=c;i++)
			cout<<"1 0 ";
	}

}


void p2(int a, int b, int c, int d)
{
	cout<<"1 ";
	b--;
	for(int i=1;i<=a;i++)
	{
		b--;
		cout<<"0 1 ";
	}

	cout<<"2 ";
	c--;
	for(int i=1;i<=b;i++)
	{
		c--;
		cout<<"1 2 ";
	}
	if(d==c)
	{
		for(int i=1;i<=d;i++)
		{
			cout<<"3 2 ";
		}
	}
	else
	{
		cout<<"3 ";
		for(int i=1;i<=c;i++)
			cout<<"2 3 ";
	}

}

void p4(int a, int b, int c, int d)
{
	cout<<"3 ";
	b--;
	for(int i=1;i<=a;i++)
	{
		b--;
		cout<<"3 2 ";
	}

	cout<<"1 ";
	c--;
	for(int i=1;i<=b;i++)
	{
		c--;
		cout<<"2 1 ";
	}
	if(d==c)
	{
		for(int i=1;i<=d;i++)
		{
			cout<<"0 1 ";
		}
	}
	else
	{
		cout<<"0 ";
		for(int i=1;i<=c;i++)
			cout<<"1 0 ";
	}

}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a, b, c, d;
	cin>>a>>b>>c>>d;
	int a1=a, b1=b, c1=c, d1=d;

	if(A(a, b, c, d))
	{
		cout<<"YES"<<endl;
		p1(a, b, c, d);
	}
	else if(B(a, b, c, d))
	{
		cout<<"YES"<<endl;
		p2(a, b, c, d);
	}
	else if(A(d, c, b, a))
	{
		cout<<"YES"<<endl;
		p3(d, c, b, a);
	}
	else if(B(d, c, b, a))
	{
		cout<<"YES"<<endl;
		p4(d, c, b, a);
	}
	else
		cout<<"NO"<<endl;

	p3(d, c, b, a);
	cout<<endl;

	p4(d, c, b, a);
	cout<<endl;
	p1(a, b, c, d);
	cout<<endl;
	p2(a, b, c, d);

	return 0;
}