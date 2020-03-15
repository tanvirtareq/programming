#include<bits/stdc++.h>
#define dbg(a) cout<<#a<<" "<<a<<endl;

using namespace std;

const double INF = 1e100;
const double EPS = 1e-9;

double l, s, n, c;

double bns()
{

    double e=l/2.0;
    double b=125e5;


    for(int i=1; i<=100; i++)
    {

        double r=(e+b)/2.0;

        double val=cos(s/r)+l*l/(2.0*r*r)-1.0;
        dbg(val);
        cout<<r-sqrt(r*r-l*l/4.0)<<endl;

        if(val<0)
        {
            e=r;
        }
        else
            b=r;

    }

    double r=(e+b)/2.0;
    return r-sqrt(r*r-l*l/4.0);
}

int main()
{
    int t;
//    cin>>t;
    scanf("%d", &t);

    for(int in=1; in<=t; in++)
    {

//        cin>>l>>n>>c;
        scanf("%lf%lf%lf", &l, &n, &c);
//        dbg(l);
//        dbg(n);
        s=1.0+n*c;
        s=s*l;

        double ans=bns();

//        cout<<"Case "<<in<<": ";
//        cout<<setprecision(12)<<fixed<<ans<<endl;
        printf("Case %d: %.10lf\n", in ,ans);

    }

    return 0;
}

