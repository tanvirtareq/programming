#include<bits/stdc++.h>
#define is_in_range(x, y) (((x*r<=n ) and x>=0 and y>=0)? 1:0)

using namespace std;

pair<int, int> extendedEuclidean(int a,  int b)
{
//    cout<<a<<" "<<b<<endl;
    pair<int, int> p, q;

    if(a%b==0)
    {
        p.first=0;
        p.second=1;
        return p;
    }

    q=extendedEuclidean(b, a%b);

//    cout<<q.first<<" "<<q.second<<endl;
    p.first=q.second;
    p.second=q.first+(-a/b)*q.second;

//    cout<<p.first<<" "<<p.second<<endl;
    return p;

}

pair<int, int> extendedEuclideanCover(int a, int b)
{
    pair<int, int> p;
    p=extendedEuclidean(max(abs(a), abs(b)), min(abs(a), abs(b)));

    if(abs(b)>abs(a)) swap(p.first, p.second);

//    cout<<p.first<<" "<<p.second<<endl;

    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

//    cout<<p.first<<" "<<p.second<<endl;

    return p;

}

pair<int, int>  find_one_solution_of_linear_diophantine_equation(int a, int b, int c)
{
    pair<int, int> p, q;

    int g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
        cout<<"no solution"<<endl;
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

//    cout<<q.first<<" "<<q.second<<endl;
//    cout<<p.first<<" "<<p.second<<endl;

    return p;

}

pair<int, int> find_in_range(int x, int y, int g, int r, int l, int n)
{
    while(x*r>n)
    {
        x-=l/g;
        y-=r/g;

//        cout<<x<<" "<<y<<endl;
    }

    while(y<0 or x<0)
    {
        y+=r/g;
        x+=l/g;

        cout<<x<<" "<<y<<endl;
    }
    return make_pair(x, y);
}

int main()
{
    pair<int , int>p;
    int n, l, r, t, c;
    cin>>c;

    while(c--)
    {
        cin>>n>>l>>r>>t;
        t--;

        int g=__gcd(l, r);

        if(t%g!=0)
        {
            cout<<"uh-oh!"<<endl;

            continue;
        }

        p=find_one_solution_of_linear_diophantine_equation(r, -l, t);

        int x=p.first;
        int y=p.second;

        if(!is_in_range(x, y))
        {
            cout<<x<<" "<<y<<endl;

            p=find_in_range(x, y, g, r,l, n);

            x=p.first;
            y=p.second;
        }

        int x1=x;
        int y1=y;

        cout<<x<<" "<<y<<endl;

        int mn=INT_MAX;

        while(is_in_range(x1, y1))
        {


            mn=min(mn, x1+y1);
            x1+=l/g;
            y1+=r/g;

            cout<<x1<<" "<<y1<<endl;
        }

        x1=x;
        y1=y;

        while(is_in_range(x1, y1))
        {
//            cout<<x1<<" "<<y1<<endl;

            mn=min(mn, x1+y1);
            x1-=l/g;
            y1-=r/g;

            cout<<x1<<" "<<y1<<endl;
        }

        if(mn==INT_MAX)
        {
            cout<<"uh-oh!"<<endl;
        }
        else
        {
            cout<<mn<<endl;
        }


    }


    return 0;
}

/**

2
29 13 5 29


*/


