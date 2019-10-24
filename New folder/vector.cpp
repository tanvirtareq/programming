#include <bits/stdc++.h>

typedef long long int dll;

using namespace std;

template<class t1, class t2>

class node
{
    public:
    t1 n;
    t2 f;
    node()
    {
        n=0;
        f=0;
    }
    node(t1 x, t2 y)
    {
        n=x;
        f=y;
    }

    float dif()
    {
        return (t2)(n-f);
    }

    inline bool operator==(node y)
    {
        if(n==y.n and f==y.f) return true;

        return false;
    }


};

int main()
{
    vector<node<int, float > >v;
    node<int, float> x;
    v.push_back(x);
    v.push_back(node<int, float> (2, 3.6));
    if(v[0]==v[1])
    cout<<v[1].dif()<<endl;

    cout<<v[1].f<<endl;

return 0;
}


