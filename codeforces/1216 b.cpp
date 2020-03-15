#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<pair<ll, ll> > v;

    ll n, sum=0;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(make_pair(x, i));

    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i=0;i<n;i++)
    {
        sum+=(i*v[i].first+1);
        // cout<<sum<<endl;
    }

    cout<<sum<<endl;

    for(int i=0;i<n;i++) cout<<v[i].second<<" ";


    
    return 0;
}
