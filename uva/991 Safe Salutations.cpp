#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll ct[20];

ll cat(ll n)
{
//    cout<<n<<endl;
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(ct[n]!=-1)
        return ct[n];
    ll ans =0;

    for(ll i=0; i<n; i++)
    {
        ans+=cat(i)*cat(n-i-1);
//        cout<<ans<<endl;
    }
    return ct[n]=ans;
}

int main()
{
    ll n;
    int f=0;

    memset(ct, -1, sizeof ct);
    while(cin>>n)
    {
        if(f==1) cout<<endl;
        cout<<cat(n)<<endl;
        f=1;
    }


    return 0;
}

