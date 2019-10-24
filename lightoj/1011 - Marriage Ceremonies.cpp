    #include<bits/stdc++.h>
     
    #define mk make_pair
    #define pb  push_back
    #define f(i, a, b)  for(ll i=a;i<=b;i++)
    #define dbg(a) cout<<#a<<"= "<<a<<endl;
     
    using namespace std;
    typedef long long ll;
    typedef long long unsigned lu;
    typedef vector<int> vi;
    typedef pair<int, int> ii;
     
    ll n, ar[20][20], dp[20][175536];
     
    ll rc(ll i, ll btmsk)
    {
        if(i>n) return 0;
        ll mx=0;
        if(dp[i][btmsk]!=-1) return dp[i][btmsk];
        for(ll j=1;j<=n;j++)
            mx=(((btmsk&(1<<j))==0))? max(mx, ar[i][j]+rc(i+1, btmsk^(1<<j))): mx;
        return dp[i][btmsk]=mx;
    }
     
    int main()
    {
     
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
     
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
     
        ll t;
        scanf("%lld", &t);
        f(in,1, t)
        {
            cin>>n;
            for(ll i=1;i<=n;i++)
                for(ll j=1;j<=n;j++) scanf("%lld", &ar[i][j]);
     
            printf("Case %lld: ", in);
            memset(dp, -1, sizeof dp);
            printf("%lld\n", rc(1, 0));
        }
        return 0;
    }

