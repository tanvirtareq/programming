#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long int lld;

struct  propnode
{
	lld sum;
	lld prop;
	propnode()
	{
		prop=0;
		sum=0;
	}
};

void build(lld ar[], lld node, lld low, lld high, propnode tree[])
{
	if(low==high)
	{
		tree[node].sum=ar[low];

		//cout<<"node arpos val"<<endl;
		//cout<<node<<" "<<low<<" "<<ar[low]<<endl;
		return;
	}

	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	//cout<<"node left right low high"<<endl;
	//cout<<node<<" "<<left<<" "<<right<<" "<<low<<" "<<high<<endl;

	build(ar, left, low, mid, tree);
	build(ar, right, mid+1, high, tree);

	tree[node].sum=tree[left].sum+tree[right].sum;

	return;

}

void update(lld ar[], lld node, lld low, lld high, lld ul, lld uh, lld val,  propnode tree[])
{
	if(ul<=low and uh>=high)
	{
	   //cout<<"low  high  sum"<<endl;
		//cout<<low<<" "<<high<<" "<<tree[node].sum<<endl;
		tree[node].prop+=val;
		tree[node].sum+=(high-low+1)*val;

		//cout<<"low high node sum  propagation"<<endl;

		//cout<<low<<" "<<high<<" "<<node<<" "<<tree[node].sum<<" "<<tree[node].prop<<endl;

		//cout<<node<<"  "<<tree[node].sum<<endl;
		//cout<<low<<" "<<high<<" "<<tree[node].sum<<endl;
		return;
	}

	if(uh<low or ul>high)
	{
		return;
	}



	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	update(ar, left, low, mid, ul, uh, val, tree);
	update(ar, right, mid+1, high, ul, uh,val, tree);

	tree[node].sum=tree[left].sum+tree[right].sum+(high-low+1)*tree[node].prop;

	//cout<<"node  sum"<<endl;
	//cout<<node<<" "<<tree[node].sum<<endl;

	return;

}

lld query(lld ar[], lld node, lld low, lld high, lld ul, lld uh, lld carry,  propnode tree[])
{

	//cout<<"node  carry"<<endl;
	//cout<<node<<" "<<carry<<endl;
	if(ul<=low and uh>=high)
	{
		//cout<<"node  pre sum aft sum"<<endl;
		lld x=tree[node].sum+(high-low+1)*(carry);
		//cout<<node<<" "<<tree[node].sum<<" "<<x<<endl;

		return x;
	}

	if(uh<low or ul>high)
	{
		return 0;
	}



	lld left=2*node;
	lld right=left+1;
	lld mid=(low+high)/2;

	lld x=query(ar, left, low, mid, ul, uh, carry+tree[node].prop, tree);
	lld y=query(ar, right, mid+1, high, ul, uh,carry+tree[node].prop, tree);

	//cout<<x+y<<endl;

	return x+y;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

//	int ar[1000]= {0};
//	 propnode tr[1000];
//
//    update(ar, 1, 1, 8, 2, 6, 1 , tr);
//    update(ar, 1, 1, 8, 1, 8, 1, tr);
//    update(ar, 1, 1, 8, 5, 6, 1, tr);
//
//    cout<<query(ar, 1, 1, 8, 5, 6, 0, tr)<<endl;

	lld n, t, c;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		lld ar[n+10]={0};
		propnode tree[5*n+10];
		memset(tree, 0, sizeof(tree));
		//build(ar, 1, 1, n, tree);
		while(c--)
		{
			lld x;
			cin>>x;
			if(x==0)
			{
				lld p, q, v;
				cin>>p>>q>>v;

				update(ar, 1, 1, n, p, q, v, tree);
			}
			else
			{
				lld p, q;
				cin>>p>>q;

				lld y=query(ar, 1, 1, n, p, q, 0,tree);
				cout<<y<<endl;
			}
		}

		//cout<<tree[3].sum<<endl;
		//cout<<3<<"  "<<tree[3].sum<<endl;

	}


	return 0;
}
