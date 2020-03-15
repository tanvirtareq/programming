#include<bits/stdc++.h>

#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl
#define md 1000000007

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;
 ll n, m;
 ll dpt[2000][2000][20];
ll dp(ll a, ll b, ll st)
{
    if(st>=m) return 1;
    cout<<a<<" "<<b<<" "<<st<<endl;
//    if(dpt[a][b][st]!=-1) return dpt[a][b][st];

    ll mx=0;
    for(ll i=a;i<=n;i++)
    {
        for(ll j=1;j<=min(b, i);j++)
        {
            mx=(mx+dp(i, j, st+1))%md;
        }
    }
    return dpt[a][b][st]=mx;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    memset(dpt, -1, sizeof dpt);

//    cout<<dp(0, n, 1)<<endl;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            {

            }

    cout<<dpt[0][0][0]<<endl;

    return 0;
}



