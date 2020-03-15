#include<bits/stdc++.h>


#define sci(a) scanf("%d", &a)
#define v(a) vector<a>
#define p(a, b) pair<a, b>

using namespace std;

typedef long long int li;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

template<class T>
void inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

    for(int i=x;i>=0;i--)
    {
        if(a&((T)1<<i))
        cout<<1;
        else cout<<0;

    }
    cout<<endl;

    return;

}

li inline power(li b, li p)
{
    if(b==2) return (li)1<<(p);

    if(p==0) return 1;

    if(p==1) return b;

    li x=power(b, p/2);

    if(p&1)
    {
        return b*x*x;
    }

    else return x*x;

}


int main()
{
    int a, d, m, g, p, b;

    cin>>a>>d>>m>>g>>p>>b;

//    cout<<a<<g<<endl;

    if(g<a)
    {

        cout<<"NO"<<endl;

        return 0;

    }

    else if(g>=a)
    {
        g=g-a;
        a=0;

    }

    if(m>=b)
    {

        m=m-b;
        b=0;
    }

    else
    {
        b=b-m;
        m=0;
    }

    if(m>(g+b+p))
    {
        cout<<"NO"<<endl;
        return 0;

    }

    if(m>=g)
    {
        m=m-g;
        g=0;

    }

    else
    {
        g=g-m;

        m=0;
    }

        int ds=g+p;



//        cout<<s<<endl;

        if(d>ds)
        {
            cout<<"NO"<<endl;

            return 0;
        }

        else
        {
            ds=ds-d;
            d=0;

        }

        int s=ds+g;

        if(m>s)
        {
            cout<<"NO"<<endl;

            return 0;
        }

        cout<<"YES"<<endl;

        return 0;


	return 0;
}

