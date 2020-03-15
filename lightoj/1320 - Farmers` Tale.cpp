#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct PT {
    ll x, y;
};

struct Line{
    ll a, b, c;
    Line(){};
    Line(PT s, PT e)
    {
        a=s.y-e.y;
        b=-s.x+e.x;
        c=s.y*(s.x-e.x)-s.x*(s.y-e.y);
        ll g=__gcd(a, __gcd(a, b));
        a=a/g;
        b=b/g;
        c=c/g;
    }
};

struct poly{
    vector<PT> p;

};

void cutpoly(vector<PT> &pl1, vector<PT> &pl2, Line ln, vector<PT> pl)
{
    for(int i=0;i<pl.size();i++)
    {
        int fc=side(lin, pl[i]);
        if(fc>0) pl1.push_back(pl[i]);
        if(fc<0) pl2.push_back(pl[i]);
    }
}

vector<poly> cut(vector<poly> v, Line ln)
{
    vector<poly> v1;
    for(int i=0;i<v.size();i++)
    {
        poly pl=v[i];
        vector<Pt> pl1, pl2;
        cutpoly(pl1, pl2, ln, pl);
        if(pl1.size()>2) v1.push_back(pl1);
        if(pl2.size()>2) v1.push_back(pl2);

    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll in=1;in<=t;in++)
    {
        ll n, L, W;
        cin>>n>>w;
        vector<poly> v;

        poly pl;
        pl.p.push_back({0, 0});
        pl.p.push_back({L, 0});
        pl.p.push_back({L, W});
        pl.p.push_back({0, W});
        v.push_back(pl);
        while(n--)
        {
            ll x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            v=cut(v, Line({x1, y1} {x2, y2}));
        }
        cout<<"Case "<<in<<": "<<v.size()<<endl;
    }

}
