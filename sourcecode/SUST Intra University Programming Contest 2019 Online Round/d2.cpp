#include<bits/stdc++.h>

#define f(i, n) for(int i=1;i<=n;i++)
#define sci(a) scanf("%d", &a)
#define wi(a) printf("%d\n", a)
#define dbg printf("yes\n")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef priority_queue<int> pqi;
typedef priority_queue<int , vector<int> , greater<int> > mnpqi;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin>>n;

	int ar[n+10];
	map<int ,int> mp; 
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		mp[ar[i]]=i;
	}

	int ct=mp[1];

	int pv=n;

	for(int i=2;i<=n;i++)
	{
		int tmp=mp[i]-mp[i-1];

		ct+=(0+tmp+pv)%pv;
		cout<<i<<" "<<(0+tmp+pv)%pv<<endl;

		pv--;

	}
	// ct++;

	cout<<ct<<endl;

	return 0;
}
