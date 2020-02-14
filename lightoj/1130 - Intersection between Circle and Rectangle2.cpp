#include<bits/stdc++.h>

using namespace std;

const double INF = 1e100;
const double EPS = 1e-9;


struct PT
{
    double x,y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}     PT(const PT &p) : x(p.x), y(p.y)    {}     void in()
    {
        sf("%lf %lf",&x,&y);
    }
    void out()
    {
        pf("%.10f %.10f\n",x,y);
    }
    PT operator + (const PT &a) const
    {
        return PT(x+a.x,y+a.y);
    }
    PT operator - (const PT &a) const
    {
        return PT(x-a.x,y-a.y);
    }
    PT operator * (const double a) const
    {
        return PT(x*a,y*a);
    }
    friend PT operator * (const double &a, const PT &b)
    {
        return PT(a * b.x, a * b.y);
    }
    PT operator / (const double a) const
    {
        P a g e | 301

        return PT(x/a,y/a);
    }
    bool operator==(PT a)const
    {
        return sign(a.x-x)==0&&sign(a.y-y)==0;        //return point that is truncated the distance from center to r     PT trunc(double r){         double l=val();
    }
    bool operator<(PT a)const
    {
        return sign(a.x-x)==0?sign(y-a.y)<0:x<a.x;
    }
    bool operator>(PT a)const
    {
        return sign(a.x-x)==0?sign(y-a.y)>0:x>a.x;
    }
    double val()
    {
        return sqrt(x*x+y*y);
    }
    double val2()
    {
        return (x*x+y*y);
    }
    double arg()
    {
        return atan2(y,x);
    }

    return PT(x*r,y*r);
}
};

int main()
{
    return 0;
}


