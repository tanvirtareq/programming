#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(int i=a;i<=b;i++)
#define	mx	1500000
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int sg[4*mx], ar[mx];

void show(int ar[], int n)
{
	f(i, 1, n)
	{
		cout<<ar[i]<<" ";
	}

	cout<<endl<<endl<<endl;
}

void init(int pos, int st, int ed)
{
	if(st==ed){ sg[pos]=1; return;}

	int lft=2*pos;
	int rt=lft+1;
	int md=(st+ed)/2;

	init(lft, st, md);
	init(rt, md+1, ed);

	sg[pos]=sg[lft]+sg[rt];

	return;
}

void dlt(int pos, int st, int ed, int ind)
{
	// cout<<st<<" "<<ed<<" "<<ind<<endl;

	if(st==ed) {
		sg[pos]=0;
		return;
	}

	int lft=2*pos;
	int rt=lft+1;
	int md=(st+ed)/2;

	if(ind<=sg[lft])
	{
		dlt(lft, st, md, ind);
	}

	else 
	{
		dlt(rt, md+1, ed, ind-sg[lft]);
	}

	sg[pos]=sg[lft]+sg[rt];

	return;

}

int fnd(int pos, int st, int ed, int ind)
{
	if(st==ed) {
		
		return ar[st];
	}

	int lft=2*pos;
	int rt=lft+1;
	int md=(st+ed)/2;

	if(ind<=sg[lft])
	{
		return fnd(lft, st, md, ind);
	}

	else 
	{
		return fnd(rt, md+1, ed, ind-sg[lft]);
	}


}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	f(i, 1, mx)
	{
		ar[i]=i;
	}

	init(1, 1, mx);

	// show(sg, 4*mx);

	int k=0;

	for(int i=2;i<=mx;i+=2)
	{
		dlt(1, 1, mx, i-k);
		k++;
	}

	for(int i=2;i<=mx;i++)
	{
		int k=0;
		int f=fnd(1, 1, mx, i);
		for(int j=f;j<=mx;j=j+f)
		{
			dlt(1,1, mx, j-k);
			 k++;
			 // show(sg, 4*mx);

		}
		// show(sg, 4*mx);
	}
	// cout<<"ed"<<endl;

	int t;
	cin>>t;

	f(i, 1, t)
	{
		int x;
		cin>>x;

		cout<<"Case "<<i<<": "<<fnd(1, 1, mx, x)<<endl;
	}



	return 0;
}