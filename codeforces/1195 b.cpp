#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;

typedef long long ll;

int main()
{
//   #ifndef ONILINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;

    ll a=1;
    ll b=3;
    ll c=-2*n-2*k;

    ll x=b*b-4*a*c;
    double y=sqrt((double)x);
    ll an1=(-b+y)/2;
    ll an2=(-b-y)/2;

    ll ans1=n-an1;
    ll ans2=n-an2;

    (ans1>=0 && an1>=0)? cout<<ans1<<endl:cout<<ans2<<endl;

    return 0;
}

