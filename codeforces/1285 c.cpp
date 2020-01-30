#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x, ans=1;
    cin>>x;
    for(ll i=1;i*i<=x;i++) if(x%i==0 and __gcd(i, x/i)==1) ans=i;
    cout<<ans<<" "<<x/ans<<endl;
    return 0 ;
}
