#include<bits/stdc++.h>
#define ll long long

using namespace std;


pair<ll, ll> extendedEuclidean(ll a,  ll b)
{
    pair<ll, ll> p, q;

    if(a%b==0)
    {
        p.first=0;
        p.second=1;
        return p;
    }

    q=extendedEuclidean(b, a%b);
    p.first=q.second;
    p.second=q.first+(-a/b)*q.second;
    return p;

}

pair<ll, ll> extendedEuclideanCover(ll a, ll b)
{
    pair<ll, ll> p;
    p=extendedEuclidean(abs(a), abs(b));


    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

    return p;

}

ll modularMultiplicativeInverse(ll a, ll m)
{
    pair<ll,  ll> p=extendedEuclideanCover(a, m);

    if(p.first<0) p.first+=m;
    return p.first;

}

ll chineseRemainderTheorem(ll number[], ll remainder[],ll n)
{
    ll product=1;

    ll x=0;

    for(ll i=0;i<n;i++)
        product*=number[i];

    ll pp[n+10];

    for(ll i=0;i<n;i++){

        ll pp=product/number[i];

        ll modInv=modularMultiplicativeInverse(pp, number[i]);

        x+=pp*modInv*remainder[i];
    }

    return x%product;
}


int main()
{

    ll t;
    cin>>t;

    for(ll k=1;k<=t;k++)
    {
        ll n;
        cin>>n;
        ll p[n], r[n];
        for(ll i=0;i<n;i++)
        {
            cin>>p[i]>>r[i];
        }


        cout<<"Case "<<k<<": "<<chineseRemainderTheorem(p, r, n)<<endl;
    }

    return 0;
}

