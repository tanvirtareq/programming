#include<bits/stdc++.h>

#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lu a, b, c;
	cin>>a>>b>>c;

	cout<<(a+b)/c<<" ";
	(a%c+b%c)<c? cout<<0<<endl: cout<<min(c-a%c, c-b%c)<<endl;

	// lu x=a/c+b/c;

	lu m=a%c;
	lu n=b%c;

	// cout<<m<<" "<<n<<endl;
	// x+=(m+n)/c;

	// cout<<x<<" ";
	// cout<<min(m, n)<<endl;
	// // (m+n)>=c? cout<<min(m, n)<<endl:cout<<0<<endl;


	return 0;
}