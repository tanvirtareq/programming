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



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double l, h, x;
	cin>>h>>l;

	x=(l*l-h*h)/(2*h);

	cout<<fixed<<setprecision(13);
	cout<<x<<endl;

	return 0;
}