//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<cmath>


using namespace std;

struct point
{
    int x, y;

};

bool cmpr(point a, point b)
{
    if(a.x<=b.x)
        return true;


    return false;


}
//point ar[110];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;

    int ct=0;

    while(cin>>n>>d)
    {
        ct++;
        if(n==0 and d==0)
            break;


        vector<point> v;

        int np=0;


        for(int i=1; i<=n; i++)
        {
            int x, y;
            point a;

            cin>>a.x>>a.y;

            if(a.y>d) np=1;

            v.push_back(a);

        }

        if(np==1) {
            cout<<"Case "<<ct<<": "<<-1<<endl;
            continue;
        }

        if(n==1)
        {
            cout<<"Case "<<ct<<": "<<1<<endl;
            continue;
        }

        sort(v.begin(), v.end(),  cmpr);

        stack<double> st;

        double temp=(double)(d*d-v[0].y*v[0].y);
        if(temp<0)
        {
            cout<<"Case "<<ct<<": "<<-1<<endl;
            continue;
        }

        double x1=v[0].x+sqrt(temp);

        st.push(x1);

        int flag=1;

        for(int i=1; i<n; i++)
        {
            double temp=(double)(d*d-v[i].y*v[i].y);
            if(temp<0)
            {
                cout<<"Case "<<ct<<": "<<-1<<endl;
                flag=0;
                break;
            }

            x1=v[i].x+sqrt((double)(d*d-v[i].y*v[i].y));
            double x2=v[i].x-sqrt((double)(d*d-v[i].y*v[i].y));

            if( x2<=st.top() and x1>=st.top())
                continue;

            else if(x2> st.top())
            {
                st.push(x1);
            }
            else if(x1<st.top())
            {
                st.pop();
                st.push(x1);

            }

        }

        if(flag)
        cout<<"Case "<<ct<<": "<<st.size()<<endl;

    }


    return 0;
}

/**

3 2
1 2
-3 1
2 1

1 2
0 2

0 0
*/

