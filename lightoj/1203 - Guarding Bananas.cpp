#include<bits/stdc++.h>

#define inp(a) scanf("%d%d", &a.x, &a.y)
#define out(a) cout<<a.x<<a.y<<endl
#define sci(a) scanf("%d", &a)
#define clr(a) memset(a, 0, sizeof a)

using namespace std;

typedef long long ll;

#define isEqual(a, b) ((a.x==b.x and a.y==b.y)?1:0)
#define distsq(a, b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct pt
{
    ll x, y;
    pt operator - (pt a)
    {
        return {x-a.x, y-a.y};
    }
};
ll dot(pt a, pt b)
{
    return a.x*b.x+a.y*b.y;
}
bool cmp(pt a, pt b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt> &a)
{
    if (a.size() == 1)
        return a;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (i == a.size() - 1 || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2))
        {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

    return a;
}

double angle(pt a, pt b, pt c )
{
    ll dt=dot(a-b,  c-b);
    ll fc=dot(a-b, a-b)*dot(c-b, c-b);
    return (double)dt/sqrt((double)fc);
}

int main()
{
    ll t;
    cin>>t;
    for(int in=1; in<=t; in++)
    {
        ll n;
        cin>>n;
        vector<pt> p;
        for(int i=0;i<n;i++)
        {
            ll x, y;
            cin>>x>>y;
            p.push_back({x, y});
//            cout<<it.x<<" "<<it.y<<endl;
        }
        if(n<3)
        {
            printf("Case %d: 0\n", in);
            continue;
        }


        for(int i=0;i<p.size();i++)
        {
            cout<<p[i].x<<" "<<p[i].y<<endl;
        }
        p=convex_hull(p);
//        for(int i=0;i<p.size();i++)
//        {
//            cout<<p[i].x<<" "<<p[i].y<<endl;
//        }
        double mnans=1e9;
        for(int i=0; i<n; i++)
        {
            cout<<p[i].x<<" "<<p[i].y<<endl;
            mnans=min(mnans, angle(p[(i-1+n)%n], p[i], p[(i+1)%n]));
        }
        printf("Case %d: %.6lf\n", in, mnans);
    }


    return 0;
}


