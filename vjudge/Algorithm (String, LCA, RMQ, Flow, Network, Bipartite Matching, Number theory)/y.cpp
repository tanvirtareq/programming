#include<bits/stdc++.h>
#define is_in_range(xval, yval, xmin, ymin, xmax, ymax) (((((xval)>=xmin) and (xval)<=xmax) and ((yval)>=ymin) and ((yval)<=ymax))? 1: 0)
using namespace std;

typedef long long ll;

pair<ll, ll> extendedEuclidean(ll a,  ll b)
{
    pair<ll, ll> p, q;

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

pair<ll, ll> extendedEuclideanCover(ll a, ll b)
{
    pair<ll, ll> p;
    p=extendedEuclidean(abs(a), abs(b));

    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

    return p;

}

pair<ll, ll>  find_one_solution_of_linear_diophantine_equation(ll a, ll b, ll c)
{
    pair<ll, ll> p, q;

    ll g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
//        cout<<"no solution"<<endl;
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

    return p;

}

ll number_of_solution(ll a,ll b,ll c,ll xmin,ll  ymin,ll xmax, ll ymax)
{
    if(a<0)
    {
        ll temp=xmax;
        a=-a;
        xmax=-xmin;
        xmin=-temp;

    }

    if(b<0)
    {
        ll temp=xmax;
        b=-b;
        ymax=-ymin;
        ymin=-temp;

    }

    pair<ll, ll> p;
    p=find_one_solution_of_linear_diophantine_equation(a, b, c);

    ll g=__gcd(abs(a), abs(b));

    ll x0=p.first;
    ll y0=p.second;

    ll ap=a/g;
    ll bp=b/g;

    ll minm1=ceil((double)(y0-ymax)/ap);
//    cout<<minm1<<endl;

    ll minm2=ceil((double)(xmin-x0)/bp);



    ll minm=max(minm1, minm2);

    ll maxm1=floor((double)(y0-ymin)/ap);
    ll maxm2=floor((double)(xmax-x0)/bp);

    cout<<maxm1<<endl;

    ll maxm=min(maxm1, maxm2);

    cout<<maxm<<endl;

    return maxm-minm+1;
}


int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    while(cin>>n)
    {
        if(n==0) break;

        pair<ll , ll> p=find_one_solution_of_linear_diophantine_equation(9L, 1L, n);

        ll x0=p.first;
        ll y0=p.second;

        cout<<x0<<" "<<y0<<endl;

        vector<ll> v;

        for(ll k=-x0+1; x0+k<10;k++)
        {
            if(y0-9*k>=0 and y0-9*k<10)
            v.push_back(10*(x0+k)+y0-9*k);

        }

        sort(v.begin(), v.end());

        cout<<v[0];
        for(ll i=1;i<v.size();i++)
        {
            cout<<" "<<v[i];
        }
        cout<<endl;

    }

    return 0;
}


