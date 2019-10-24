#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int iniat_minsegtree(int node, int b, int e, int ar[], int minsegtree[])
{


	if(b==e)
	{
		minsegtree[node]=ar[b];
		return minsegtree[node];
	}
	int left=2*node;
	int right=2*node+1;

	int mid=(b+e)/2;

	int p1=iniat_minsegtree(left, b, mid, ar, minsegtree);
	int p2=iniat_minsegtree(right, mid+1, e, ar, minsegtree);
	minsegtree[node]=min(p1, p2);


	return minsegtree[node];



}


int findmin(int node, int b, int e, int i, int j, int ar[], int minsegtree[])
{
	if(b>i&&e<j)
	{
		return minsegtree[node];
	}

	else if(b>=j||e<=j)
	{
		return INT_MAX;
	}

	else
	{
		int left=2*node;
		int right=2*node+1;

		int mid=(b+e)/2;

		int p1=findmin(left, b, mid,i, j, ar, minsegtree);
		int p2=findmin(right, mid+1, e,i,j, ar, minsegtree);

		return min(p1, p2);

	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	int t, n, q, i, j;
	scanf("%d", &t);
	for(int k=1;k<=t;k++)
	{
		//cout<<"Case "<<k<<":"<<endl;
		printf("Case %d:\n", k);

		//cin>>n>>q;
		scanf("%d%d", &n, &k);

		int ar[n+10], minsegtree[3*n+10];
		for(int l=1;l<=n;l++)
		{
			//cin>>ar[l];
			scanf("%d", &ar[l]);

		}

		iniat_minsegtree(1, 1, n, ar, minsegtree);

		while(q--)
		{
			//cin>>i>>j;
			scanf("%d%d", &i, &j);

			int min=findmin(1, 1,n, i, j, ar, minsegtree);
			//cout<<min<<endl;
			printf("%d\n", min);

		}
		
	}


	return 0;
}
