#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

struct ii{
 ll x, y;
 ii operator - (ii a)
 {
     return {x-a.x, y-a.y};
 }
};

ll cross(ii a, ii b)
{
    return a.x*b.y-a.y*b.x;
}
ll dot(ii a, ii b)
{
    return a.x*b.x+a.y*b.y;
}

ll distsq(ii a, ii b)
{
    return dot(a-b, a-b);
}

ll intersect(ii a, ii b,ii c, ii d)
{
    if(((cross(b-a, c-a)*cross(b-a, d-a))<0) and ((cross(d-c, b-c)*cross(d-c, a-c))<0)) return 1;
    return 0;
}

int point_on_angle(ii a, ii b, ii c,ii p)
{
//    return 0;
    if(cross(c-b, p-b)*cross(a-b, p-b)<0) return 1;
    return 0;
}

ll shoot(ii ar[], ii p, ii sh)
{
    ll ct=0;
    for(ll i=1;i<=n;i++)
    {
        ll j=i+1;
        if(j>n) j=1;

//         if((ar[i].y==p.y) and (p.x<=ar[i].x) and (ar[i].x<=sh.x)) ct+=2;
        if((ar[i].y==p.y and ar[j].y!=p.y) and (p.x<=ar[i].x) and (ar[i].x<=sh.x))
        {
            ll k=i-1;
            if(k<1) k=n;
            if(point_on_angle(ar[k], ar[i], ar[j], p)) ct++;
            else
                ct+=2;
        }
        else if((ar[i].y==p.y and ar[j].y==p.y) and (p.x<=ar[i].x) and (ar[i].x<=sh.x))
        {
            while(ar[j].y==p.y)
            {
                j++;
                if(j>n) j=1;
            }
            ll k=i-1;
            if(k<1) k=n;
            while(ar[k].y==p.y)
            {
                k--;
                if(k<1) k=n;
            }
            if(point_on_angle(ar[k], ar[i], ar[j], p)) ct++;
        }
        else
        {
            if(intersect(ar[i], ar[j], p, sh)) ct++;
//            cout<<ct<<endl;
        }
    }
//    cout<<ct<<endl;
    return ct;
}
ll eq(ii a, ii b)
{
    return ((a.x==b.x) && (a.y==b.y));
}
ll onsegment(ii a, ii b, ii c)
{
    if(eq(a, c) || eq(b, c)) return 1;
    ll d=dot(b-a, c-a);
    if(d<0) return 0;
    if((cross(b-a, c-a)==0) and (distsq(a, c)<=distsq(b, a))) return 1;
    return 0;
}
int main()
{
    ll t;
    cin>>t;
    for(ll in=1; in<=t; in++)
    {
        cin>>n;
        ii ar[n+10];
        for(ll i=1; i<=n; i++)
            cin>>ar[i].x>>ar[i].y;
        ll q;
        cout<<"Case "<<in<<":"<<endl;
        cin>>q;
        while(q--)
        {
            ii pt;
            cin>>pt.x>>pt.y;
            ii sh={10003, pt.y};
            ll f=0;
            for(ll i=1;i<=n;i++)
            {
                ll j=i+1;
                if(j>n) j=1;
                if(onsegment(ar[i], ar[j], pt)) f=1;
            }

            if(f) cout<<"Yes"<<endl;
            else
            {
                ll ct=shoot(ar, pt, sh);
                if(ct%2) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}

