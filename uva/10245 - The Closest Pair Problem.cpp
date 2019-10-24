#include<bits/stdc++.h>
#define inp(a) cin>>a.x>>a.y;
#define dist(a, b) sqrt((a.x-b.x)*(a.x-b.x)+((a.y-b.y)*(a.y-b.y)))

using namespace std;

struct point{
double x, y;

};

bool cmpX(point a, point b)
{
    if(a.x<b.x) return true;

    return false;

}

bool cmpY(point a, point b)
{
    if(a.y<b.y) return true;

    return false;

}

double merg(point strip[], int sz, double d)
{
    double mn=d;

    sort(strip, strip+sz, cmpY);

    for(int i=0;i<sz-1;i++)
    {
        if(dist(strip[i], strip[i+1])<mn)
        {
            mn=dist(strip[i], strip[i+1]);
        }
        if(i+2<sz and  dist(strip[i], strip[i+2])<mn)
        {
            mn=dist(strip[i], strip[i+1]);
        }

    }

    return mn;

}

double bruteForce(point p[], int n)
{
    double mn=DBL_MAX;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mn=min(mn, dist(p[i], p[j]));
        }
    }

    return mn;

}

double closestpair(point p[], int n)
{

    if(n<=3)
    {
        return bruteForce(p, n);
    }

    int mid=n/2;

    double dr=closestpair(p, mid);
    double dl=closestpair(p+mid,n-mid);

    double d=min(dr, dl);

    point strip[n];

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(abs(p[i].x-p[mid].x)<=d)
        {
            strip[j++]=p[i];
        }

    }

    return min(d, merg(strip, j, d));

}

int main()
{
    int n;

    while(cin>>n)
    {
        if(n==0) break;

        point p[n+10];

        for(int i=0;i<n;i++)
        {
            inp(p[i]);
        }

        sort(p, p+n, cmpX);

        double x=closestpair(p, n);

        if(x>=10000)
            cout<<"INFINITY"<<endl;

        else cout<<x<<endl;
    }

    return 0;
}



