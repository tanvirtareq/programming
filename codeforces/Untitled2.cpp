#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lu long long
#define pr pair<ll, vector<ll> >

/** ntt /  calculate those constant first / calculation: / mod=c*2^k+1 / find any c and k; / find g = primitive root of mod / find root=g^c / find root_1=modular multiplicative inverse / root=(1/root)%mod / find root_pw=2^k */
const ll mod = 998244353;
const ll root = 15311432;
const ll root_1 = 469870224;
const ll root_pw = 1 << 23;

lu power(lu b,lu p)
 {
 	if(p==0) return 1;
 	if(p==1) return b;
 	lu x=power(b, p/2)%mod;
 	x=(x*x)%mod;
 	if(p&1) x=(x*b)%mod;
 	return x;
 }

 lu inverse(lu n, lu m)
 {
 	lu x=power(n, m-2);
 	return x%mod;
 }

void fft(vector<ll> & a, bool invert)
{
    ll n = a.size();
    for (ll i = 1, j = 0; i < n; i++)
    {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (ll len = 2; len <= n; len <<= 1)
    {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);
        for (ll i = 0; i < n; i += len)
        {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++)
            {
                ll u = a[i+j], v = (ll)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }
    if (invert)
    {
        ll n_1 = inverse(n, mod);
        for (ll & x : a)
            x = (ll)(1LL * x * n_1 % mod);
    }
}

/* this function take to array of coefficient of two polynomial
and return an array of coefficient of a polynomial which is multiplication of previous polynomial */
vector<ll> multiply(vector<ll> & a, vector<ll> & b)
{
    ll n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (ll i = 0; i < n; i++)
    a[i]=(a[i] *b[i])%mod;
    fft(a, true);

     for(int i=a.size()-1;i>=0;i--)
    {

        if(a[i]) break;
        a.pop_back();
    }

    return a;
}

 /** primitive root generator */
ll generator (ll p)
{
    vector<ll> fact;
    ll phi = p-1,  n = phi;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
    for (ll res=2; res<=p; ++res)
    {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= power(res, phi / fact[i]) != 1;
        if (ok)
            return res;
    }
    return -1;
}
vector<vector<ll> > vc;

int dnc(int st, int ed)
{
	if(st==ed)
		return st;

	if(abs(st-ed)==1)
	{
		multiply(vc[st], vc[ed]);
		return st;
	}
	int md=(st+ed)/2;
	int a1=dnc(st, md);
	int a2=dnc(md+1, ed);
	multiply(vc[a1], vc[a2]);

	return a1;
}


int main()
{
	lu n;
    scanf("%lld", &n);
	map<lu, lu> mp;
	map<lu, lu> :: iterator it;
	for(lu i=1;i<=n;i++)
	{
		lu x;
        scanf("%lld", &x);
		mp[x]++;
	}

	it=mp.begin();

	while(it!=mp.end())
    {
        int a=it->second;
        vector<ll> v;
        for(int i=0;i<=a;i++) v.push_back(1);
        vc.push_back(v);
        it++;
    }
    ll ansi=dnc(0, vc.size()-1);
	printf("%lld", vc[ansi][n/2]);

	return 0 ;
}
