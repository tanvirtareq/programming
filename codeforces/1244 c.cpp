#include<bits/stdc++.h>

#define ll long long
using namespace std;
// typedef long long ll

pair<ll , ll > extendedEuclidean(ll a,  ll b)
{
    pair<ll , ll > p, q;

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

pair<ll , ll > extendedEuclideanCover(ll a, ll b)
{
    pair<ll , ll > p;
    p=extendedEuclidean(abs(a), abs(b));

    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

    return p;

}

pair<ll , ll >  find_one_solution_of_linear_diophantine_equation(ll a, ll b, ll c)
{
    pair<ll , ll > p, q;

    ll g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
        cout<<"-1"<<endl;
        exit(0);
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

    return p;

}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n, p, w, d;
    cin>>n>>p>>w>>d;

    pair<ll , ll > fc=find_one_solution_of_linear_diophantine_equation(w, d, p);
    ll g=__gcd(w, d);
    ll x=fc.first;
    ll y=fc.second;

    // cout<<x<<" "<<y<<endl;

    // ll m=(p-n*d-w*x+d*x)*g/(d*(w-d));

    if(d==w)
    {
        ll m=-x*g/d;
        x=x+m*d/g;
        y=y-m*w/g;
        ll z=n-x-y;

        if(x>=0 && y>=0 and z>=0){ 
        cout<<x<<" "<<y<<" "<<z<<endl;
        return 0;
        }



        cout<<-1<<endl;
        return 0;
    }

    ll tp1=p-n*d;
    ll tp2=w-d;
    ll fk=tp1/tp2+(tp1%tp2>0);
    // cout<<fk<<endl;
    ll nmr=(fk-x)*g;
    ll mf=nmr/d+(nmr%d>0);
    // cout<<mf<<endl;
    // cout<<mf*d/g+x<<endl;

    // ll m=(ll)ceil((double)(max(0LL, (ll)ceil((double)tp1/tp2)-x)*(double)g/d));
    ll m=mf;

    x=x+m*d/g;
    y=y-m*w/g;
    ll z=n-x-y;


    // cout<<x<<" "<<y<<endl;
    // cout<<x+y<<endl;

    if(x>=0 && y>=0 and z>=0){ 
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
    }

    x=fc.first;
    y=fc.second;

    m=(max(0LL, (p-n*w)/(d-w))-y)*g/w;

    y=y+m*w/g;
    x=x-m*d/g;
    z=n-x-y;

    if(x>=0 && y>=0 and z>=0){ 
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
    }



    cout<<-1<<endl;

    
    return 0;
}