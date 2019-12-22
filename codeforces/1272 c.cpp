#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned
#define ii pair<int, int>
#define vi vector<int>


using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    string x;
    cin>>n>>k>>x;
    char ch[k+10];
    map<char , int> mp;

    for(int i=1;i<=k;i++)
    {
        char chk;
        cin>>chk;
        mp[chk]=1;
    }

    ll ans=0;
    ll ct=0;
    for(ll i=0;i<n;i++)
    {
        if(mp[x[i]]==1)
        {
            ct++;
        }
        else
        {
            ans+=ct*(ct+1)/2;
            ct=0;
        }
    }
     ans+=ct*(ct+1)/2;
    cout<<ans<<endl;

    return 0;
}

