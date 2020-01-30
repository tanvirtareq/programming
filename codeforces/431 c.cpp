#include<bits/stdc++.h>
#define MX 200000
#define ll long long
#define md 1000000007
using namespace std;
ll n, k, d, dpt[1000][2];
ll dp(ll tk, bool y)
{

    if(y==1 and tk==n) return 1;
    if(tk>=n) return 0;
    if(dpt[tk][y]!=-1) return dpt[tk][y];
    ll mx=0;
    for(int i=1;i<=k;i++)
    {
        bool f=max(y, i>=d);
        mx=(mx+dp(tk+i, f))%md;
        if(tk+i>n) break;
    }
    return dpt[tk][y]=mx;

}
int main()
{
    cin>>n>>k>>d;
    memset(dpt, -1, sizeof dpt);
    ll mx=0;
    for(int i=1;i<=k;i++)
    {
        bool f=i>=d;
        mx=(mx+dp(i, f))%md;
    }
    cout<<mx<<endl;
    return 0;
}


