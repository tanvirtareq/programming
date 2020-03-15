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

pair<ll, ll>  find_one_solution_of_linear_diophantine_equation(ll a, ll b, ll c)
{
    pair<ll, ll> p, q;

    ll g=__gcd(a, b);

    if(c%g!=0)
    {
        // cout<<"no solution"<<endl;
        return p;
    }

//    cout<<g<<endl;

    q=extendedEuclidean(a,b);

    p.first=q.first*(c/g);
    p.second=q.second*(c/g);

    return p;

}


ll find_for_x(ll xval, ll yval, ll incriminent, ll xmin, ll ymin, ll xmax, ll ymax)
{


    if(xval+incriminent>=xmin and xval+incriminent<=xmax)
    {
        return find_for_x(xval+incriminent, yval-incriminent,incriminent, xmin, ymin, xmax, ymax);
    }
    else{
            return xval;
    }
}

ll number_of_solution(ll a, ll b, ll c, ll xmin, ll ymin, ll xmax, ll ymax)
{
    if(a==0 and b==0 and c==0)
    {
        return (xmax-xmin+1)*(ymax-ymin+1);
    }
    if(a==0 and b==0 ) return 0;

    // cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==0)
    {
        ll y=c/b;
        if(c%b!=0) return 0;
        if(y>ymax || y<ymin) return 0;

        return xmax-xmin+1;
    }

    if(b==0)
    {
        ll x=c/a;
        if(c%a!=0) return 0;
        if(x>xmax || x<xmin) return 0;

        return ymax-ymin+1;
    }

    pair<ll, ll> p;
    p=find_one_solution_of_linear_diophantine_equation(a,b, c);


    ll g=__gcd(abs(a), abs(b));

    if(c%g!=0) return 0;

    ll l=abs(a)*(abs(b)/g);
    // cout<<g<<endl;

    ll x0=p.first;
    ll y0=p.second;

    // cout<<x0<<" "<<y0<<endl;

    if(-(a/abs(a))*(b/abs(b))>0)
    {
        l=-l;
        ll k1=(xmin-x0)*((double)a/l);
        ll k2=(y0-ymin)*((double)b/l);

        ll kmin=max(k1, k2);

        ll k3=(xmax-x0)*((double)a/l);
        ll k4=(y0-ymax)*((double)b/l);

        ll kmax=min(k3, k4);

        // cout<<(x0+kmin*l/a)<<" "<<(y0-kmin*l/b)<<endl;

        while(kmin<=kmax && ((x0+kmin*(l/a))<xmin || (y0-kmin*(l/b))<ymin))
            kmin++;

        while(kmin<=kmax && ((x0+kmax*(l/a))>xmax || (y0-kmax*(l/b))>ymax))
            kmax--;

        // cout<<kmin<<" "<<kmax<<endl;

        return max(kmax-kmin+1, 0LL);

    }

    if(-(a/abs(a))*(b/abs(b))<0)
    {
        if(a<0) l=-l;
        // cout<<l<<endl;
        ll k1=(xmin-x0)*((double)a/l);
        ll k2=(y0-ymax)*((double)b/l);

        ll kmin=max(k1,  k2);

        ll k3=(xmax-x0)*((double)a/l);
        ll k4=(y0-ymin)*((double)b/l);

        ll kmax=min(k3, k4);
        // cout<<kmin<<" "<<kmax<<endl;

        // cout<<(y0-kmin*l/b)<<endl;

        while(kmin<=kmax && ((x0+kmin*(l/a))<xmin || (y0-kmin*(l/b))>ymax))
            kmin++ ;

        while(kmin<=kmax && ((x0+kmax*(l/a))>xmax || (y0-kmax*(l/b))<ymin))
            kmax--;

        // cout<<kmin<<" "<<kmax<<endl;

        return max(kmax-kmin+1, 0LL);

    }

    // ll lx=find_for_x(p.first, p.second, -p.second/g, xmin, ymin, xmax, ymax);
    // ll rx=find_for_x(p.first, p.second, p.second/g, xmin, ymin, xmax, ymax);

    // return (rx-lx)/(p.second/g);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll t;
    cin>>t;
    // cout<<t<<endl;
    for(ll i=1;i<=t;i++)
    {

        pair<ll , ll>p;
        ll a, b, c, xmin, ymin, xmax, ymax;


        cin>>a>>b>>c>>xmin>>xmax>>ymin>>ymax;
        if(b<0)
        {
            a=-a;
            b=-b;

            c=-c;
        }

        // cout<<"as"<<endl;

        cout<<"Case "<<i<<": ";
        cout<<number_of_solution(a, b, -c, xmin, ymin, xmax, ymax)<<endl;
    }

    return 0;
}

///  1 1 5 -5 10 2 4



