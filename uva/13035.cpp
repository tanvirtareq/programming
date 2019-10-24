#include<bits/stdc++.h>

#define mx  30000
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mk make_pair
#define f(i, a, b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll p=1000000007;

int invm(ll b, ll pr)
{
    ll x=b;
    ll ret=1;

    while(pr)
    {
        if(pr&1) ret=(ret*x)%p;

        // cout<<ret<<endl;

        x=(x*x)%p;
        // cout<<x<<endl;
        pr=pr/2;
    }

    // cout<<"gi"<<endl;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

    int t;
    cin>>t;
    // cout<<t<<endl;

    ll inv=invm(6, p-2);
    // cout<<inv<<endl;
    ll inv1=invm(2, p-2);
    for(int i=1;i<=t;i++)
    {

        ll n;
        cin>>n;
        // cout<<n<<endl;

        ll i2=(n*(n+1))%p;
        i2=(i2*((2*n+1)%p))%p;
        // cout<<i2<<endl;
        i2=(i2*inv)%p;
        // cout<<i2<<endl;

        ll i1=(n*(n+1))%p;

        i1=(inv1*i1)%p;


        ll ans=(i2+i1+p)%p;
        cout<<"Case "<<i<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

///  1 1 5 -5 10 2 4



