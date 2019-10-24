#include<bits/stdc++.h>
using namespace std;


pair< int, pair<int, int> > extendedEuclidean(int a,  int b)
{
    pair< int, pair<int, int> > p, q;

    if(a%b==0)
    {
        p.second.first=0;
        p.second.second=1;
        p.first=b;
        return p;
    }

    q=extendedEuclidean(b, a%b);
    p.second.first=q.second.second;
    p.second.second=q.second.first+(-a/b)*q.second.second;
    p.first=q.first;
    return p;

}

pair<int, pair<int, int> > extendedEuclideanCover(int a, int b)
{
    pair< int, pair<int, int> >  p;
    p=extendedEuclidean(abs(a), abs(b));

    if(a<0) p.second.first=-p.second.first;
    if(b<0) p.second.second=-p.second.second;

    return p;

}

int main()
{

    int a, b;
    while(cin>>a>>b)
    {
        pair<int, pair<int, int> > p;

        if(a==b)
        {
            cout<<0<<" "<<1<<" "<<a<<endl;
        }
        else
        {
            p=extendedEuclideanCover(a, b);
            cout<<p.second.first<<" "<<p.second.second<<" "<<p.first<<endl;
        }

    }

    return 0;
}

