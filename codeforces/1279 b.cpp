#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define ii pair<ll, ll>
#define dbg(a) cout<<#a<<"="<<a<<endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n, s;
        cin>>n>>s;
        map<ll, ll> mp;
        ll ar[n+10], br[n+10], mx[n+10];
        memset(ar, 0, sizeof ar);
        memset(br, 0, sizeof br);
        memset(mx, 0, sizeof mx);
        for(ll i=1;i<=n;i++)
        {
            cin>>ar[i];
            if(mp[ar[i]]==0)
               mp[ar[i]]=i;
            br[i]=br[i-1]+ar[i];
            mx[i]=max(mx[i-1], ar[i]);
        }
        int fc=0;

        for(ll i=n;i>0;i--)
        {
            if(br[i]<=s)
            {
                cout<<0<<endl;
                fc=1;
                break;
            }
            else if(br[i]-mx[i]<=s)
            {
                cout<<mp[mx[i]]<<endl;
                fc=1;
                break;
            }
        }
        if(fc==0)
        {
            cout<<0<<endl;
        }
    }

}

/**
1
4 10
1 2 3 4

1
4 6
1 2 3 5

1
4 5
1 2 3 1


*/


