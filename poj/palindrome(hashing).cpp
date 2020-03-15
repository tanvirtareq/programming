
#include<iostream>
#include<vector>
#include <stdio.h>      /* printf */
#include <assert.h>
#include <algorithm>
#define ll long long
#define ii pair<int, int>
#define N 1000100
#define dbg(a) cout<<#a<<" "<<a<<endl;
using namespace std;

ii pw[N], invpw[N];
const int p1=137, p2=277;
const int MOD1=127657753, MOD2=987654319;
int invp1, invp2;

ll qpow(ll n, ll k, ll mod)
{
    ll ans =1;
//    n%=mod;
    while(k>0)
    {
        if(k&1)
            ans=(ans*n)%mod; n=(n*n)%mod; k>>=1;
    }
    return ans%mod;
}
void pre()
{
    invp1=qpow(p1, MOD1-2, MOD1);
    invp2=qpow(p2, MOD2-2, MOD2);
    invpw[0]= {1, 1};
    pw[0]= {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first=1LL*pw[i-1].first*p1%MOD1;
        pw[i].second=1LL*pw[i-1].second*p2%MOD2;
        invpw[i].first=1LL*invpw[i-1].first*invp1%MOD1;
        invpw[i].second=1LL*invpw[i-1].second*invp2%MOD2;
    }
    return;
}

struct RollingHash
{
    int n;
    string s;/// 0-indexed
//    vector<ii> hs;/// 1- indexed
    ii hs[N];
    void init(string &s)
    {
        n=0;
//        s.clear();
//        hs.clear();
        n=s.size();
//        s=_s;
//        hs.push_back({0, 0});
        hs[0]={0, 0};
        for(int i=0; i<n; i++)
        {
            ii p;
            p.first=(hs[i].first+1LL*pw[i].first*s[i])%MOD1;
            p.second=(hs[i].second+1LL*pw[i].second*s[i])%MOD2;
//            hs.push_back(p);
            hs[i+1]=p;
        }
        return;
    }
    /// returns hash of substring [l....r], 1-indexed
    ii get_hash(int l, int r)
    {
        ii ans;
        ans.first=(hs[r].first-hs[l-1].first+MOD1)*1LL*invpw[l-1].first%MOD1;
        ans.second=(hs[r].second-hs[l-1].second+MOD2)*1LL*invpw[l-1].second%MOD2;
        return ans;
    }
};


int n;


 RollingHash h, hulta;

int bsfodd(int i, int a, int b)
{

    if(a==b) return a;

    int m=(a+b)/2;
    if((a+b)%2) m++;
    if(h.get_hash(i-m+1, i)!=hulta.get_hash(n-i-m, n-i-1)) return bsfodd(i, a, m-1);
    else return bsfodd(i, m, b);
}

int bsfeven(int i, int a, int b)
{
    if(a==b) return a;
    int m=(a+b)/2;
    if((a+b)%2) m++;

    if(h.get_hash(i-m+2, i+1)!=hulta.get_hash(n-i-m, n-i-1)) return bsfeven(i, a, m-1);
    return bsfeven(i, m, b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
    string s, sulta;
    int in=0;
    while(cin>>sulta)
    {
        in++;
        if(sulta=="END") break;
        s=sulta;
        n=s.size();
        reverse(sulta.begin(), sulta.end());
        h.init(s);
        hulta.init(sulta);
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
            mx=max(mx, 1+2*bsfodd(i,0,  min(i, n-i-1)));
            mx=max(mx, 2*bsfeven(i, 0, min(i+1, n-i-1)));
        }
        cout<<"Case "<<in<<": "<<mx<<endl;
    }
    return 0;
}
