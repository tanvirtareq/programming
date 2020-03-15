#include<bits/stdc++.h>
typedef long long int dll;

using namespace std;


class MyClass
{
    dll p;
     dll operator^(dll b)
    {
        return power(b, p);
    }


    inline power(dll b, dll p)
    {
        if(p==0) return 1;
        if(p==1) return b;

        if(p&1)
        {
            dll x;
            x=power(b, p/2);

            return x*x*b;
        }

        else
        {
            dll x;
            x=power(b, p/2);
            return x*x;
        }
    }


};


class Mint
{
    public:
    dll v;
    Mint()
    {
       v=0;
    }
    Mint(dll x)
    {
       v=x;
    }

    dll operator^(Mint b);

//    Mint &operator=(T x)
//    {
//        v=x;
//    }
};

dll power(dll b, dll p)
{
    if(p==1) return b;
    if(p==0) return 1;

    if(p&1==0)
    {
        dll x=power(b, p/2);
        return x*x;
    }

    else
    {
        dll x=power(b, p/2);
        return x*x*b;
    }
}

dll  Mint::operator^(Mint b)
{
    return power(v, b.v);
}

int main()
{
    Mint x=10, y=3;
    dll z=x^y;
    cout<<z<<endl;
    return 0;
}
