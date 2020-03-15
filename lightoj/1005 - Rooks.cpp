#include<bits/stdc++.h>

#define mk make_pair
#define	pb	push_back
#define f(i, a, b)	for(int i=a;i<=b;i++)
#define	mx	1500000
#define dbg(a) cout<<#a<<"= "<<a<<endl;
 
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);
	f(in,1, t)
	{
		lu n, k;
		scanf("%llu%llu", &n, &k);
		if(k>n)
		{
			printf("Case %d: 0\n", in);
			continue;
		}
		if(k==0)
		{
			printf("Case %d: 1\n", in);
			continue;
		}
		lu ans=n;
		for(lu i=1;i<k;i++) ans=(ans/i)*(n-i);
		ans=ans/k;
		ans*=ans;
		for(int i=1;i<=k;i++) ans*=i;
		printf("Case %d: %llu\n", in, ans);
	}



	return 0;
}