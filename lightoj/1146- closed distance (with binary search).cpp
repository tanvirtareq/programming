#include<bits/stdc++.h>
#define cinc(a) cin>>a.x>>a.y
#define dist(a, b) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
#define er 1e-15

using namespace std;
typedef long double ld;

struct point{
ld x, y;

};

point inline mdl(point a, point b)
{
    point m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;

    return m;

}

ld func(point a, point b, point c, point d)
{
    ld ac=dist(c , a);
    ld bd=dist(d , b);

    if(fabs(ac-bd)<=er){

        point m1=mdl(a, b);
        point m2=mdl(c, d);

        return dist(m1, m2);
    }

    point m1=mdl(a, b);
    point m2=mdl(c, d);

    if(ac>bd)
        return func(m1, b, m2, d);

    else return func(a, m1 , c, m2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {

        point a, b, c, d;

        cinc(a);
        cinc(b);
        cinc(c);
        cinc(d);



        cout<<"Case "<<i<<": ";
        cout<<fixed<<setprecision(10)<<func(a, b, c, d)<<endl;

    }


    return 0;
}

