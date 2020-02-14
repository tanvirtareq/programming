
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, sum=0, s0=0;

        cin>>n;
        while(n--)
        {
            ll x;
            cin>>x;
            sum+=x;
            if(x==0) s0++;
        }

        if(s0==0)
        {
            if(sum) cout<<0<<endl;
            else cout<<1<<endl;
        }

        else
        {
            if(sum+s0) cout<<s0<<endl;
            else cout<<s0+1<<endl;

        }

    }

    return 0;
}
