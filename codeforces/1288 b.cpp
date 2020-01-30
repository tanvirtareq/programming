#include<bits/stdc++.h>

#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int>, greater<int> > mnpqi;

ll chk(ll A, ll B, ll x)
{
    return min(A, min(B, x));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll A, B;
        cin>>A>>B;
        ll d=log10(B+1);
        cout<<d*A<<endl;
//        ll x=10;
//        ll mx=0;
//        while(x<A+B)
//        {
//            mx+=chk(A, B, x);
//            x=x*10;
//        }
//        cout<<mx<<endl;

    }
    return 0;
}


