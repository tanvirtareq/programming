#include<bits/stdc++.h>

#define ll long long
using namespace std;

struct rc{
    double xmin,xmax, ymin, ymax;

};

  rc a, b, c;

int ismd(double x, double y)
{
    cout<<b.xmin<<" "<<b.xmax<<" "<<b.ymin<<" "<<b.ymax<<endl;
    if(b.xmin<x and x<b.xmax and b.ymin<y and y<b.ymax) return 0;
    if(c.xmin<x and x<c.xmax and c.ymin<y and y<c.ymax) return 0;

    // if(b.xmin==x and )


    return 1;

}


int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

  

    double x1, x2, y1, y2;

    cin>>x1>>y1>>x2>>y2;

    a.xmin=min(x1, x2);
    a.ymin=min(y1, y2);
    a.xmax=max(x1, x2);
    a.ymax=max(y1, y2);

    cin>>x1>>y1>>x2>>y2;

    b.xmin=min(x1, x2);
    b.ymin=min(y1, y2);
    b.xmax=max(x1, x2);
    b.ymax=max(y1, y2);

    cin>>x1>>y1>>x2>>y2;

    c.xmin=min(x1, x2);
    c.ymin=min(y1, y2);
    c.xmax=max(x1, x2);
    c.ymax=max(y1, y2);

    for(int i=a.xmin;i<=a.xmax;i+=0.5)
    {

        if(ismd(i, a.ymin))
        {
            // cout<<i<<" "<<a.ymin<<endl;
            cout<<"YES"<<endl;
            exit(0);
        }

    }

    for(int i=a.xmin;i<=a.xmax;i+=0.5)
    {

        if(ismd(i, a.ymax))
        {
            cout<<"YES"<<endl;
            exit(0);
        }

    }

    for(int i=a.ymin;i<=a.ymax;i+=0.5)
    {

        if(ismd(a.xmin, i))
        {
            cout<<"YES"<<endl;
            exit(0);
        }

    }

    for(int i=a.ymin;i<=a.ymax;i+=0.5)
    {

        if(ismd(a.xmax, i))
        {
            cout<<"YES"<<endl;
            exit(0);
        }

    }

    cout<<"NO"<<endl;

    return 0;
}
