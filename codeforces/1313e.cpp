#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 1100000
using namespace std;

ii pw[N], invpw[N];
const int p1=137, p2=277;
const int MOD1=127657753, MOD2=987654319;
int invp1, invp2;

ll qpow(ll n, ll k, ll mod)
{
    ll ans =1;
    assert(k>0);
    n%=mod;
    while(k>0)
    {
        if(k&1)
            ans=(ans*n)%mod; n=(n*n)%mod; k>>=1;
    }
    return ans%mod;
}
void pre()
{
    pw[0]= {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first=1LL*pw[i-1].first*p1%MOD1;
        pw[i].second=1LL*pw[i-1].second*p2%MOD2;
    }

    invp1=qpow(p1, MOD1-2, MOD1);
    invp2=qpow(p2, MOD2-2, MOD2);
    invpw[0]= {1, 1};
    for(int i=1; i<N; i++)
    {
        invpw[i].first=1LL*invpw[i-1].first*invp1%MOD1;
        invpw[i].second=1LL*invpw[i-1].second*invp2%MOD2;
    }
}

struct RollingHash
{
    int n;
    string s;/// 0-indexed
    vector<ii> hs;/// 1- indexed
    void init(string _s)
    {
        n=_s.size();
        s=_s;
        hs.push_back({0, 0});
        for(int i=0; i<n; i++)
        {
            ii p;
            p.first=(hs[i].first+1LL*pw[i].first*s[i]%MOD1)%MOD1;
            p.first=(hs[i].first+1LL*pw[i].first*s[i]%MOD1)%MOD1;
            hs.push_back(p);
        }
    }

    /// returns hash of substring [l....r], 1-indexed
    ii get_hash(int l, int r)
    {
        ii ans;
        ans.first=(hs[r].first-hs[l-1].first+MOD1)%MOD1*1LL*invpw[l-1].first%MOD1;
        ans.second=(hs[r].second-hs[l-1].second+MOD2)%MOD2*1LL*invpw[l-1].second%MOD2;
        return ans;
    }
};

int n, m;
string a, b, s;
RollingHash ah, bh, sh, srh;
int as[N], brs[N];

int bs(int id,int st, int ed, RollingHash ah, RollingHash sh)
{
//    cout<<id<<endl;
    while(st<ed)
    {

//        cout<<st<<" "<<ed<<endl;
        int m=(st+ed)/2;
        int x=st+ed;
        if(x&1) m++;
        if(ah.get_hash(id, m)!=sh.get_hash(1, m-id+1))
        {
            ed=m-1;
        }
        else st=m;
    }
    int m=(st+ed)/2;
    int x=st+ed;
    if(x&1) m++;
    if(m-id==0 and ah.s[id-1]!=sh.s[0]) return 0;
    return m-id+1;

}

int main()
{
    pre();


    cin>>n>>m>>a>>b>>s;


    ah.init(a);
    sh.init(s);
    reverse(b.begin(), b.end());
    reverse(s.begin(), s.end());
    bh.init(b);
    srh.init(s);
//    cout<<ah.get_hash(1, 2).first<<endl;

    for(int i=1;i<=n;i++)
    {
        as[bs(i, i,n, ah, sh)]++;
    }
//    cout<<"ahfd"<<endl;


    for(int i=1;i<=n;i++)
    {
        brs[bs(i, i, n, bh, srh)]++;
    }

    for(int i=m;i>=1;i--)
    {
        cout<<i<<" "<<brs[i]<<endl;
        as[i]+=as[i+1];
        brs[i]+=brs[i+1];
    }
    brs[0]=0;

    for(int i=1;i<=m;i++) brs[i]+=brs[i-1];
    cout<<brs[m]<<endl;

    ll ans=0;
    for(int i=1;i<m;i++)
        ans+=as[i]*(brs[m]-brs[m-i]);
    cout<<ans<<endl;




    return 0;
}
