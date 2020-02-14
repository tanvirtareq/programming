#include<bits/stdc++.h>
#define ll long long
#define MX 1001000

using namespace std;

vector<ll> pr[MX];
double dp[MX];

void pre()
{
    for(ll i=1;i<=MX;i++) pr[i].push_back(i);

    for(ll i=2;i<=MX;i++)
    {
        if(pr[i].size()==1)
        {
            for(ll j=i+i;j<=MX;j+=i)
            {
                pr[j].push_back(i);
            }
        }
    }
}

double dpf(ll n)
{
    if(n==1) return 0;
    if(dp[n]>=0) return dp[n];

    double ans=0;
    for(ll i=0;i<pr[n].size();i++)
    {
        ans+=dpf(pr[n][i]);
    }
    ans=ans/pr[n].size();

    return dp[n]=ans;
}

int main()
{
    pre();

    for(int i=1;i<=MX;i++) dp[i]=-1.0;

    ll t;
    cin>>t;
    for(int in=1;in<=t;in++)
    {
        ll n;
        cin>>n;

        cout<<dpf(n)<<endl;
    }

    return 0;
}

