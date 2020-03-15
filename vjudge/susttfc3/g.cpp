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

li lg(li n)
{
    li x=0;

    if(n==0) return 0;

    while(n>>1)
    {
        x++;
        n=n>>1;

    }
//    cout<<x<<endl;
    return x;

}

template<class T>
pair<li, li> inline showbinaryrepresentation_of_pos_int(T a)
{
    T x=log(a)/log(2)+1;

//    cout<<a<<endl;

li a1=0, a0=0;

li l=0;

if(a&((T)1<<x)) l=1;

    for(int i=x;i>=0;i--)
    {
        if(a&((T)1<<i)){
//                l=1;
//        cout<<l;
        a1++;
        }
        else{
            a0++;
//            l=0;
//                cout<<l;
        }

    }
//    cout<<endl;

if(l==0) a0--;
    cout<<a1<<" "<<a0<<endl;

    return make_pair(a1, a0);

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    li n;

    cin>>t;

    while(t--)
    {

        cin>>n;

        pair<li, li> p;
        p=showbinaryrepresentation_of_pos_int(n);

        li a=p.first;
        li b=p.second;

//        cout<<a<<b<<endl;

        if(n%2==0)
        {
            cout<<2*b-1<<" "<<2*a<<endl;
        }
        else
        {
            cout<<2*b<<" "<<2*a<<endl;
        }



    }


	return 0;
}


