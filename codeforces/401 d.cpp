#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"= "<<a<<endl

using namespace std;

ll dpt[(1LL<<19)][110];

string s;
int n;



ll dpf(ll mask, ll m)
{
    ll pos=__builtin_popcount(mask);
    if(pos==s.size())
        return (m==0);
    if(dpt[mask][m]!=-1)
        return dpt[mask][m];
    ll ans=0;
    bool bol[12]={0};
    for(int i=0; i<s.size(); i++)
    {
        if((mask&(1LL<<i))==0 && !bol[s[i]-'0']){
            bol[s[i]-'0']=1;
            ans+=dpf(mask|(1LL<<i),(m*10+s[i]-'0')%n);
        }
    }
    return dpt[mask][m]=ans;
}

int main()
{
    cin>>s>>n;

    memset(dpt, -1, sizeof dpt);

    ll ans =0;
bool bol[12]={0};
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='0' && !bol[s[i]-'0']){
            bol[s[i]-'0']=1;
            ans+=dpf(1LL<<i, (s[i]-'0')%n);
        }
    }
    cout<<ans<<endl;

    return 0;
}
