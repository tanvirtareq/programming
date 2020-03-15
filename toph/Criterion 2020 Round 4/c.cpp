#include<bits/stdc++.h>
#define ll long long

using namespace std;
#define pi  3.14159265358979323846
#define MX 100000010

ll qpow(ll n,ll k,ll mod){
	ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1)
	ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
	const int MOD1=127657753,MOD2=987654319;
	const int p1=137,p2=277;
	int invp1,invp2;
	pii pw[N],invpw[N];
	void pre()
	{
		pw[0]={1,1};
		for(int i=1;i<N;i++){
		pw[i].F=1LL*pw[i-1].F*p1%MOD1;
		pw[i].S=1LL*pw[i-1].S*p2%MOD2;
	}
	invp1=qpow(p1,MOD1-2,MOD1);
	invp2=qpow(p2,MOD2-2,MOD2);
	invpw[0]={1,1};
	for(int i=1;i<N;i++){
		invpw[i].F=1LL*invpw[i-1].F*invp1%MOD1;
		invpw[i].S=1LL*invpw[i-1].S*invp2%MOD2;
	}
}
///returns hash of string s
pii get_hash(string s)
{
	int n=s.size();
	pii ans={0,0};
	for(int i=0;i<n;i++){
		ans.F=(ans.F+1LL*pw[i].F*s[i]%MOD1)%MOD1;
		ans.S=(ans.S+1LL*pw[i].S*s[i]%MOD2)%MOD2;
	}
	return ans;
}

struct RollingHash
{
	int n;
	string s;///0-indexed
	vector<pii>hs;///1-indexed
	void init(string _s)
	{
		n=_s.size();
		s=_s;
		hs.eb(0,0);
		for(int i=0;i<n;i++){
			pii p;
			p.F=(hs[i].F+1LL*pw[i].F*s[i]%MOD1)%MOD1;
			p.S=(hs[i].S+1LL*pw[i].S*s[i]%MOD2)%MOD2;
			hs.pb(p);
		}
	}
///returns hash of substring [l....r],1-indexed
	pii get_hash(int l,int r)
	{
		pii ans;
		ans.F=(hs[r].F-hs[l-1].F+MOD1)%MOD1*1LL*invpw[l-1].F%MOD1;
		ans.S=(hs[r].S-hs[l-1].S+MOD2)%MOD2*1LL*invpw[l-1].S%MOD2;
		return ans;
	}
///returns hash of total string
	pii get()
	{
		return get_hash(1,n);
	}
};
RollingHash h;
int main()
{
	BeatMeScanf;
	int i,j,k,n,m;
///never forget to initialize pre()
	pre();
	string s;
	cin>>s;
	h.init(s);
	while(1){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(h.get_hash(a,b)==h.get_hash(c,d))<<nl;
	}
	return 0;
}
