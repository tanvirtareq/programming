#include<bits/stdc++.h>
#define dbg(a) cout<<#a<<" "<<a<<endl;
#define ll long long
using namespace std;
const double INF = 1e100;
const double EPS = 1e-9;

struct PT{
    ll x, y;
    PT operator - (PT a)
    {
        return {x-a.x, y-a.y};
    }
};

ll dot(PT a, PT b)
{
    return a.x*b.x+a.y*b.y;
}
ll cross(PT a , PT b)
{
    return a.x*b.y-a.y*b.x;
}
double abs(PT a)
{
    return sqrt(dot(a, a));
}

double dist2D(PT a, PT b)
{
    return abs(b-a);
}

double DistToLine(PT p, PT a, PT b)
{
    return abs(((double)cross(b-a, p-a)))/abs(b-a);
}

double DistToLineSegment(PT p, PT A, PT B)
{
    PT c;
    if(dot(B-A,p-A)<EPS) return dist2D(p, A);
    if(dot(A-B,p-B)<EPS) return dist2D(p, B);

    return DistToLine(p, A, B);
}



int main()
{
    ll t;
    cin>>t;
    for(ll in=1; in<=t; in++)
    {
        ll n;
        cin>>n;
        PT b[n+10];
        for(ll i=0;i<n;i++) cin>>b[i].x>>b[i].y;
        ll m;
        cin>>m;
        PT a[m+10];
        for(ll i=0;i<m;i++) cin>>a[i].x>>a[i].y;

        double mn=INF;

        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
//                cout<<DistToLineSegment(b[j], a[i], a[(i+1)%m])<<endl;
                mn=min(mn, DistToLineSegment(b[j], a[i], a[(i+1)%m]));
            }
//            cout<<endl<<endl;
        }
        cout<<setprecision(10)<<fixed;
        cout<<"Case "<<in<<": "<<mn/2.0<<endl;
    }
    return 0;
}
