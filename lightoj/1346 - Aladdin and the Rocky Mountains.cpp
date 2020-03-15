#include<bits/stdc++.h>
#define ll long long
#define EPS 1e-9
using namespace std;

ll n;

struct ii{
 double x, y;
 ii operator - (ii a)
 {
     return {x-a.x, y-a.y};
 }
};

double cross(ii a, ii b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(ii a, ii b)
{
    return a.x*b.x+a.y*b.y;
}

double distsq(ii a, ii b)
{
    return dot(a-b, a-b);
}
double dist(ii a, ii b)
{
    return sqrt(dot(a-b, a-b));
}

ii intersect(ii a, ii b, ii c)
{
    double a1=a.y;
    double b1=-a.x;
    double c1=0;
    double m=(b.y-c.y)/(b.x-c.x);
    double a2=m;
    double b2=-1;
    double c2=m*b.x-b.y;
    c2=-c2;
    double denom=a1*b2-a2*b1;
    if(denom<=EPS) return {-1, -1};
    double x=(b1*c2-b2*c1)/denom;
    double y=(c1*a2-c2*a1)/denom;
    return {x, y};
}

int main()
{
    ll t;
    cin>>t;
    for(ll in=1; in<=t; in++)
    {
        double fc;
        cin>>n>>fc;
        ii ar[n+10];
        for(ll i=1; i<=n; i++)
        {
            cin>>ar[i].x>>ar[i].y;
            ar[i].x-=fc;
        }
        ii high=ar[1];
        double ans=0.0;
        for(int i=2;i<=n;i++)
        {
            if(ar[i].y<high.y) continue;
            ii it=intersect(high, ar[i], ar[i-1]);
            if(it.x<0) continue;
            if(it.x<=ar[i].x)
            {
                ans+=dist(it, ar[i]);
                high=ar[i];
            }
        }
        cout<<"Case "<<in<<": ";
        cout<<setprecision(10)<<fixed<<ans<<endl;
    }
    return 0;
}


