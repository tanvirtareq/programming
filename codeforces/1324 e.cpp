#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, ar[20000];
ll dpt[2010][2010];
int h, l, r;


ll dpf(int st, int tk)
{
	if(st>n) return 0;

	if(dpt[st][tk]!=-1) return dpt[st][tk];
	int p, q;
	p=q=0;

	int h1=(tk+ar[st]-1)%h;
	p=dpf(st+1, h1);
	if(l<=h1 and h1<=r) p++;

	int h2=(tk+ar[st])%h;
	q=dpf(st+1, h2);
	if(l<=h2 and h2<=r) q++;

	return dpt[st][tk]=max(p, q);

}

int main()
{

	
	cin>>n>>h>>l>>r;

	memset(dpt, -1, sizeof dpt);

	for(int i=1;i<=n;i++) cin>>ar[i];

	cout<<dpf(1, 0)<<endl;

	return 0;
}