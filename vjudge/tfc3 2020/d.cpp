#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll b, ll p, ll m)
{
    if(p==0) return 1;
    if(p==1) return b%m;

    ll x=power(b, p/2, m)%m;
    ll xx=(x*x)%m;
    if(p&1) return (xx*b)%m;
    return xx;
}

ll modularMultiplicativeInverse(ll a, ll m)
{
    return power(a,  m-2, m)%m;
}
void solv2(ll n, ll p, ll r)
{
    ll ar[n+10];
    ar[0]=1;
    for(ll i=1; i<=n; i++)
        ar[i]=(ar[i-1]*i)%p;
    ll inv=modularMultiplicativeInverse(ar[n]%p, p)%p;
    for(ll i=2; i<=n; i++)
    {
        ll y=(i*r)%p;
        ll x=(y*inv)%p;
        if(x<i)
        {
            cout<<i<<" "<<x<<endl;
            return;
        }
    }
    cout<<"-1 -1"<<endl;
    return;
}
void solv1(ll n, ll p, ll r)
{
    ll l=1;
    for(ll i=2; i<p; i++)
        l=(l*i)%p;

    ll rr=1;
    for(ll i=p+1; i<=n; i++)
        rr=(rr*i)%p;

    ll b=(l*rr)%p;

    ll inv=(modularMultiplicativeInverse(b, p)*r)%p;

//    if(inv<p)
//    {
//        cout<<p<<" "<<inv<<endl;
//        return;
//    }

    for(ll i=1;i<p;i++)
    {
        ll x=(b*i)%p;
        if(x==r)
        {
            cout<<p<<" "<<i<<endl;
            return;
        }
    }
    cout<<"-1 -1"<<endl;
    return;

}

int main()
{
    ll n, p, r;
    cin>>n>>p>>r;

    if(n>=2*p)
    {
        if(r!=0)
            cout<<"-1 -1"<<endl;

        else
        {
            for(ll i=2; i<=n; i++)
            {
                if(i!=p)
                {
                    cout<<i<<" "<<1<<endl;
                    return 0;

                }
            }

            cout<<"-1 -1"<<endl;
            return 0;
        }
    }
    else if(n>=p)
    {
        if(r!=0)
            solv1(n, p, r);

        else
        {
            for(ll i=2; i<=n; i++)
            {
                if(i!=p)
                {
                    cout<<i<<" "<<1<<endl;
                    return 0;

                }
            }

            cout<<"-1 -1"<<endl;
            return 0;
        }

    }
    else
    {
        if(r!=0)
            solv2(n, p, r);

        else
            cout<<"-1 -1"<<endl;
    }

    return 0;
}
