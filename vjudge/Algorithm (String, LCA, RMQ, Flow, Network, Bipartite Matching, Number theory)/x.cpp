#include<bits/stdc++.h>
#define is_in_range(xval, yval, xmin, ymin, xmax, ymax) (((((xval)>=xmin) and (xval)<=xmax) and ((yval)>=ymin) and ((yval)<=ymax))? 1: 0)
using namespace std;

typedef long long int ll;

pair<int, int> extendedEuclidean(int a,  int b)
{
    pair<int, int> p, q;

    if(a%b==0)
    {
        p.first=0;
        p.second=1;
        return p;
    }

    q=extendedEuclidean(b, a%b);
    p.first=q.second;
    p.second=q.first+(-a/b)*q.second;
    return p;

}

pair<int, int> extendedEuclideanCover(int a, int b)
{
    pair<int, int> p;
    p=extendedEuclidean(abs(a), abs(b));

    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

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

    return p;

}

int number_of_solution(int a,int b,int c,int xmin,int  ymin,int xmax, int ymax)
{
    if(a<0)
    {
        int temp=xmax;
        a=-a;
        xmax=-xmin;
        xmin=-temp;

    }

    if(b<0)
    {
        int temp=xmax;
        b=-b;
        ymax=-ymin;
        ymin=-temp;

    }

    pair<int, int> p;
    p=find_one_solution_of_linear_diophantine_equation(a, b, c);

    int g=__gcd(abs(a), abs(b));

    int x0=p.first;
    int y0=p.second;

    int ap=a/g;
    int bp=b/g;

    int minm1=ceil((double)(y0-ymax)/ap);
//    cout<<minm1<<endl;

    int minm2=ceil((double)(xmin-x0)/bp);



    int minm=max(minm1, minm2);

    int maxm1=floor((double)(y0-ymin)/ap);
    int maxm2=floor((double)(xmax-x0)/bp);

    cout<<maxm1<<endl;

    int maxm=min(maxm1, maxm2);

    cout<<maxm<<endl;

    return maxm-minm+1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;

    while(cin>>a>>b)
    {

        pair<ll, ll> p=extendedEuclideanCover(a, b);
        pair<ll, ll> p1;
        pair<ll, ll> p2;
        int g=__gcd(a, b);

        int m1=(-p.first*g)/b;
        int m2=(p.second*g)/a;

        p1.first=p.first+(m1*b)/g;
        p1.second=p.second-(m1*a)/g;

        p2.first=p.first+(m2*b)/g;
        p2.second=p.second-(m2*a)/g;




        if(abs(p1.first)+abs(p1.second)>abs(p2.first)+abs(p2.second))
        {
            cout<<p1.first<<" "<<p1.second<<" "<<g<<endl;
        }

        else if(abs(p1.first)+abs(p1.second)<abs(p2.first)+abs(p2.second))
        {
            cout<<p2.first<<" "<<p2.second<<" "<<g<<endl;
        }

        else if(p1.first<p1.second)
        {
            cout<<p1.first<<" "<<p1.second<<" "<<g<<endl;
        }

        else if(p2.first<p2.second)
        {
            cout<<p2.first<<" "<<p2.second<<" "<<g<<endl;
        }


    }

    return 0;
}



