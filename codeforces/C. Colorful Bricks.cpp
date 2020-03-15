#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

#define mod 998244353

using namespace std;

int rec(int d)
{
    if(d<=1) return 1;
    return ((d%mod)*(rec(d-1))%mod)%mod;
}

int main()
{

   // cout<<rec(4)<<endl;

    int n, m , k, d, ans;

    cin>>n>>m>>k;

    d=k+1;
    //cout<<d<<endl;

    ans=((m%mod)*(rec(d))%mod)%mod;

    cout<<ans<<endl;

	return 0;
}



