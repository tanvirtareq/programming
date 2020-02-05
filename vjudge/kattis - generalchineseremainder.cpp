#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ext_gcd ( ll A, ll B, ll *X, ll *Y )
{
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}
pair<ll, ll> chinese_remainder_theorem( vector<ll> &A, vector<ll> &M )
{
    if(A.size() != M.size())
        return {-1,-1}; /** Invalid input*/
    ll n = A.size();
    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( ll i = 1; i < n; i++ )
    {
        ll a2 = A[i];
        ll m2 = M[i];
        ll g = __gcd(m1, m2);
        if ( a1 % g != a2 % g )
            return {-1,-1}; /** No solution exists*/
        /** Merge the two equations*/
        ll p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
        ll mod = m1 / g * m2; /** LCM of m1 and m2*/

        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        ll x = (((a1*((m2/g)%mod)%mod)*q)%mod + ((a2*((m1/g)%mod)%mod)*p)%mod) % mod;

        /** Merged equation*/
        a1 = x;
        if (a1 < 0)
            a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}


int main()
{
    ll t;
    cin>>t;
    for(ll k=1; k<=t; k++)
    {
        ll n=2;
        vector<ll> p(n), r(n);
        for(ll i=0; i<n; i++)
        {
            cin>>r[i]>>p[i];
        }
        pair<ll, ll> pa=chinese_remainder_theorem(r, p);
        if(pa.first==-1 and pa.second==-1)
            cout<<"no solution"<<endl;
        else
            cout<<pa.first<<" "<<pa.second<<endl;
    }
    return 0;
}


