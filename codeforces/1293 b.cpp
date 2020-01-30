#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    ll n;
    double d=0;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        d+=1.0/i;
    }
    cout<<d<<endl;
    return 0;
}

