#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mk(a, b) make_pair(a, b);
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int main()
{
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	int n, m;
	cin>>n>>m;
	int a[n+10]={0};
 
	int fl=0;
 
	vector<ii> v;
 
	while(m--)
	{
		int t, l, r;
 
		cin>>t>>l>>r;
 
		if(t==1)
		{
			for(int i=l;i<=r;i++)
			{
				if(i!=l && a[i]==0) 
				{
					a[i]=i+10;
				}
 
				if(i!=l && a[i]<a[i-1])
				{
					fl=1;
					break;
				}
 
			}
		}
 
		else 
		{
			v.push_back(make_pair(l, r));
 
		}
 
 
	}
 
	// for(int i=1;i<=n;i++)
	// 			cout<<a[i]<<" ";
 
	// 		cout<<endl;
 
	for(int i=0;i<v.size();i++)
	{
		ii it=v[i];
		int l=it.first;
		int r=it.second;
		int cs=0;
 
		for(int i=l+1;i<=r;i++)
		{
			// if(i!=l && i>=2 && a[i-1]==0) a[i-1]=i+9;
			if(i==2) a[1]==11;
			// if(a[i-1]==0) a[i-1]=i+9;
			if(i!=l && a[i]!=0 && a[i]<a[i-1]) cs=1;
			if(i!=l && cs==0 && a[i]==0) 
			{
 
				if(a[i-1]==0) a[i-1]=i+9;
				cs=1;
				a[i]=i+8;

				if(a[i-1]<=a[i]) a[i]=a[i-1]-1;
			}
 
			// else if(i!=l && a[i]==0) a[i]=i+1;
		}
 
		if(cs==0 && a[l]==0)
		{
			cs==1;
			a[l]=l+10;
		}
 
		if(cs==0) 
		{
			fl=1;
			break;
		}
	}
 
	for(int i=1;i<=n;i++)
		a[i]=(a[i]<=0)? 1:a[i]; 
 
	if(fl==0)
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
 
			cout<<endl;
		}
		else cout<<"NO"<<endl;
 
 
 
	return 0;
}