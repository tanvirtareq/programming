#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"= "<<a<<endl;

using namespace std;
ll ar[1000000], f[10000000], s1[10000000];
vector<ll> v;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l=0;
    ll r=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L') l++;
        else r++;
    }
    cout<<l+r+1<<endl;

    return 0;
}

