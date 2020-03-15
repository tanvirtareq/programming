#include<bits/stdc++.h>
#define cinc(a) cin>>a.x>>a.y>>a.z
#define dist(a, b) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))
#define er 1e-15

using namespace std;
typedef long double ld;

struct point{
ld x, y, z;

};

point inline mdl(point a, point b)
{
    point m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    m.z=(a.z+b.z)/2;

    return m;

}

ld func(point a, point b, point p)
{
    ld pa=dist(p , a);
    ld pb=dist(p , b);

    if(fabs(pa-pb)<=er){

        point m=mdl(a, b);

        return dist(p, m);
    }

    point m=mdl(a, b);

    if(pa>pb)
        return func(m, b, p);

    else return func(a, m, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        point a, b, p;

        cinc(a);
        cinc(b);
        cinc(p);

        ld pa=dist(p, a);
        ld pb=dist(p, b);
        ld ab=dist(a, b);

        if(pa*pa>pb*pb+ab*ab)
        {
            cout<<"Case "<<i<<": ";
            cout<<fixed<<setprecision(10)<<pb<<endl;
            continue;
        }

        if(pb*pb>pa*pa+ab*ab)
        {
            cout<<"Case "<<i<<": ";
            cout<<fixed<<setprecision(10)<<pa<<endl;
            continue;
        }


        cout<<"Case "<<i<<": ";
        cout<<fixed<<setprecision(10)<<func(a, b, p)<<endl;

    }


    return 0;
}
