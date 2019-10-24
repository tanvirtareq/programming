#include<bits/stdc++.h>
#define er 1e-4

#define scn(a) scanf("%lf%lf%lf", &a.x, &a.y, &a.z)

#define eql(a, b) ((fabs(a.x-b.x)<=er and fabs(a.y-b.y)<=er and fabs(a.z-b.z)<=er )? 1: 0)

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> pii;
typedef pair<lli, pii> pipii;

struct point{
double x, y, z;

};

point inline medium(point a, point b)
{
    point m;

    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    m.z=(a.z+b.z)/2;

    return m;

}

point inline st(point a)
{
    point b;
    b.x=a.x;
    b.y=a.y;
    b.z=a.z;

    return b;

}

void prnt(point a)
{
    cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;
}

int main()
{

   int t;

//   cin>>t;

    scanf("%d", &t);

   for(int i=1;i<=t;i++)
   {
       point a, b, m, p;

//       cin>>a.x>>a.y>>a.z>>b.x>>b.y>>b.z>>p.x>>p.y>>p.z;

        scn(a);
        scn(b);
        scn(p);

       double cs;

//       prnt(a);
//       prnt(b);
//       prnt(p);

//       cout<<fabs(a.x-p.x)<<endl;
//
//       cout<<eql(a, b)<<endl;

        if(eql(a, p) or eql(b, p))
        {
//            cout<<"yes"<<endl;

            printf("Case %d: 0\n", i);
//            printf("%lf\n", d);

            continue;
        }

        if(eql(a, b))
        {
            double d=sqrt((p.x-a.x)*(p.x-a.x)+(p.y-a.y)*(p.y-a.y)+(p.z-a.z)*(p.z-a.z));

            printf("Case %d: ", i);
            printf("%.10lf\n", d);

            continue;

        }

       while(!eql(a, b))
       {
//           m=medium(a, b);

            m.x=(a.x+b.x)/2;
            m.y=(a.y+b.y)/2;
            m.z=(a.z+b.z)/2;
//            prnt(a);
//           prnt(m);
//           prnt(b);

           double am_pm= (m.x-a.x)*(m.x-p.x)+(m.y-a.y)*(m.y-p.y)+(m.z-a.z)*(m.z-p.z);

           double am=sqrt((a.x-m.x)*(a.x-m.x)+(a.y-m.y)*(a.y-m.y)+(a.z-m.z)*(a.z-m.z));

           double pm=sqrt((p.x-m.x)*(p.x-m.x)+(p.y-m.y)*(p.y-m.y)+(p.z-m.z)*(p.z-m.z));

           cs=(am_pm)/(am*pm);

           if(fabs(cs)<=er) break;

//           if(cs>=0)
//           {
//               if((cs-er)<=0) break;
//           }
//           if(cs<=0 and (cs+er)>=0) break;

           if(cs>0)
           {
//               b=st( m);

                b.x=m.x;
                b.y=m.y;
                b.z=m.z;

           }

           if(cs<0)
           {
//               a=st(m);

                a.x=m.x;
                a.y=m.y;
                a.z=m.z;
           }

//           cout<<cs<<endl;

       }

       double d=sqrt((p.x-m.x)*(p.x-m.x)+(p.y-m.y)*(p.y-m.y)+(p.z-m.z)*(p.z-m.z));

//       cout<<"Case "<<i<<": ";

        printf("Case %d: ", i);
       printf("%.10lf\n", d);
//       cout<<d<<endl;

   }

    return 0;
}

/**

1
15 4 10 32 0 26 44 23 61

1
0 0 0 0 0 0 0 0 0

1
68 88 78 6 78 73 89 36 66

*/


