#include<bits/stdc++.h>

using namespace std;

int ar[10000000], dp[10000][1000];

int f(int i, int j)
{
	if(i>j) return 1;
	if(i==j) return 1;

	int p, q, r;
	p=q=r=1;
	r=1;

	if(dp[i][j]!=-1) return 1;

	if(ar[i]==-ar[j]) p=2;

	for(int k=i;k<j;k++)
	{
		p*=f(i, k)*f(i+1, j);
	}

	// if(ar[i]==-ar[j])
	// {
	// 	dp[i][j]=1;
	// 	return r=2*f(i+1, j-1);	
	// } 
	// p=f(i, j-1);
	// q=f(i+1, j);
	// return dp[i][j]=p*q*r;
	return dp[i][j]=p;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	memset(dp, -1, sizeof dp);
	cout<<f(1, n)<<endl;

	return 0;
}