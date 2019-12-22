#include<bits/stdc++.h>
#define dbg(a) cout<<#a<<" = "<<a<<endl;

using namespace std;

#define ll long long
#define lu long long
#define pr pair<ll, vector<ll> >

const lu mod=998244353;
const lu root=72390235;
const lu root_1=967518384;
const lu root_pw=1<<23;

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

void fft(vector<lu> & a, bool invert) {
    lu n = a.size();

    for (lu i = 1, j = 0; i < n; i++) {
        lu bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (lu len = 2; len <= n; len <<= 1) {
        lu wlen = invert ? root_1 : root;
        for (lu i = len; i < root_pw; i <<= 1)
            wlen = (lu)((1LL * wlen * wlen) % mod);

        for (lu i = 0; i < n; i += len) {
            lu w = 1;
            for (lu j = 0; j < len / 2; j++) {
                lu u = a[i+j], v = (lu)((1LL * a[i+j+len/2] * w) % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (lu)((1LL * w * wlen) % mod);
            }
        }
    }

    if (invert) {
        lu n_1 = inverse(n, mod);
        for(int i=0;i<a.size();i++){
            a[i]=(1LL*a[i]*n_1)%mod;
        }
    }
}

void multiply(vector<lu> & a, vector<lu> & b) {

    lu n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);
    for (lu i = 0; i < n; i++)
        a[i] = (a[i]*b[i])%mod;

    fft(a, true);

    for(int i=a.size()-1;i>=0;i--)
    {

        if(a[i]) break;
        a.pop_back();
    }

    return ;
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

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