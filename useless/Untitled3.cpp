#include <bits/stdc++.h>

typedef long long int dll;

using namespace std;

template<class t1>
 inline t1 rec(t1 n)
{
    //cout<<n<<endl;
//    dll a[10000];
//   int t=10000;
//    while(t-- and t>1)
//        a[t]=0;

	if(n<=1) return n;

    t1 x=n*rec(n-1);
    cout<<x<<endl;
	return x;
}

class op
{
    public:
    int n;
    op(){
//    n=0;
    };
    op(int x)
    {
        n=x;
    }

//    int operator !(int n);
};

//int op::operator !()
//{
//    int x=1;
//    for(int i=1;i<=n;i++)
//    {
//        x*=i;
//    }
//    return x;
//}


template<class x>
class v
{
public:
    x a, b, c, d;

    template<class T>
    x zug(T a, T b)
    {
        return (x)a+b;
    }
};

class loc {
  int longitude, latitude;
public:
    loc() {}
    loc(int lg, int lt) {
    longitude = lg;
    latitude = lt;
    }

    void show() {
    cout << longitude << " ";
    cout << latitude << "\n";
    }

    loc operator+(loc op2);
};
// Overload + for loc.
loc loc::operator+(loc op2)
{
    loc temp;
    temp.longitude = op2.longitude+longitude;
    temp.latitude = op2.latitude + latitude;
    return temp;
}

template<class x>
class exchange
{
public:
    exchange(){};
    x p, q;
    exchange(x a, x b)
    {
        p=a;
        q=b;
    }
    exchange(x a)
    {
        p=a;
    }

    void operator+(x &a)
    {
        x &t;
        &t=&a;
        &a=&p;
        &p=&t;
        cout<<"yes"<<endl;
    }

};

bool cmp(string x)
{
    if(x=="ab") return true;

    return false;
}

int main()
{

    cout<<(1^3^5)<<endl;

//    map<int , int >mp;
//
//    mp[1]=0;
//    mp[2]=1;
//    mp[3]=3;
//
//
//
//    string x="abcb", y="abcdef";
//    if(includes(x.begin(),x.end(),  y.begin(), y.end()))
//    {
//        cout<<"yes"<<endl;
//    }
//
////    copy(y.begin(), y.end(), x.begin());
//    for_each
//    cout<<x;

//
//    cout<<!5<<endl;
//
//    vector<int> v(5,-1);
//    v.push_back(1);
//    v[0]=2;
//    v[1]=4;
//    vector<int>:: iterator it;
//    it=v.begin();
//    v.erase(it, it+2);
//
//    v.insert(v.end()-1, 7);
//
//    cout<<v.back()<<endl;
//
////    exchange<int> ex(5), ex2(6);
////    ex+ex2;
////    cout<<ex.p<<endl;
//
////    op x(5);
////    op y(6);
////    int  z=+x;
////   cout<<z<<endl;
// loc ob1(10, 20), ob2( 5, 30);
//ob1.show(); // displays 10 20
//ob2.show(); // displays 5 30
//ob1 = ob1+ob2;
//ob1.show(); // displays 15 50
return 0;
}

