#include<bits/stdc++.h>
#define f(i, a, n) for(int i=a;i<=n;i++)
#define mx 100000
#define dbg cout<<"yes"<<endl;


using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int sg1[4*mx+10], sg2[4*mx+10], sg3[4*mx+10], lz[4*mx+10];

void show()
{

	for(int i=1;i<=10;i++)
	{
		cout<<sg1[i]<<" "<<sg2[i]<<" "<<sg3[i]<<" "<<lz[i]<<endl;
	}

	cout<<endl<<endl<<endl;
}

void init(int st, int ed, int pos)
{
	if(st==ed)
	{
		sg1[pos]=1;
		return ;
	}

	int lft=2*pos;
	int rt=lft+1;
	int md=(st+ed)/2;

	init(st, md, lft);
	init(md+1, ed, rt);

	sg1[pos]=sg1[lft]+sg1[rt];

}

int up(int a, int b, int st, int ed, int pos)
{
	// cout<<st<<" "<<ed<<" "<<pos<<endl;
	// cout<<a<<" "<<b<<endl;

	if(a>ed || b<st ) {  return 0;}

	if(st==ed)
	{
		int tmp=sg1[pos];
		sg1[pos]=sg3[pos];
		sg3[pos]=sg2[pos];
		sg2[pos]=tmp;
		return 1;
	}

	if(a<=st and b>=ed)
	{
		int tmp=sg1[pos];
		sg1[pos]=sg3[pos];
		sg3[pos]=sg2[pos];
		sg2[pos]=tmp;
		lz[pos]=(lz[pos]+1)%3;
		// dbg;
		return 1;
	}


	int lft=2*pos;
	int rt =lft+1;
	int md=(st+ed)/2;

	up(a, b, st, md, lft);
	up(a, b, md+1,ed,  rt);

	sg1[pos]=sg1[lft]+sg1[rt];
	sg2[pos]=sg2[lft]+sg2[rt];
	sg3[pos]=sg3[lft]+sg3[rt];

	lz[pos]=(lz[pos])%3;

	int x=lz[pos];

	while(x--)
	{
		int tmp=sg1[pos];
		sg1[pos]=sg3[pos];
		sg3[pos]=sg2[pos];
		sg2[pos]=tmp;

	}

	return 1;

}

int qu(int a, int b, int st, int ed, int pos, int x)
{
	// cout<<st<<" "<<ed<<endl;
	if(a>ed || b<st ) {  return 0;}

	// dbg;

	if(a<=st and b>=ed)
	{
		// dbg;
		// cout<<x<<endl;
		x=x%3;
		if(x==0) return sg1[pos];
		if(x==1) return sg3[pos];
		// dbg;
		return sg2[pos];

	}

	// dbg;

	// if(st==ed)
	// {
	// 	if(st==a and st==b)
	// 	{
	// 		if(x==0) return sg1[pos];
	// 		if(x==1) return sg3[pos];

	// 		return sg2[pos];
	// 	}
	// 	else return 0;
	// }

	

	int lft=2*pos;
	int rt =lft+1;
	int md=(st+ed)/2;

	int p=qu(a, b, st, md, lft, (x+lz[pos])%3);
	int q=qu(a, b, md+1, ed, rt, (x+lz[pos])%3);

	// cout<<st<<" "<<ed<<" "<<p+q<<endl;

	return  p+q;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, q;
	cin>>n>>q;

	init(0, n-1,1);
	// show();

	while(q--)
	{
		int x, a, b;
		cin>>x>>a>>b;

		if(x==1)
		{
			// dbg;
			// cout<<x<<" "<<q<<endl;
			int p=qu(a, b, 0, n-1, 1, 0);
			cout<<p<<endl;
		}
		else up(a, b, 0, n-1, 1);

		// show();
	}

	return 0;
}