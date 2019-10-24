#include<bits/stdc++.h>
#define er 1e-6L

#define scn(a) scanf("%Lf%Lf%Lf", &a.x, &a.y, &a.z)
#define scnc(a) cin>>a.x>>a.y>>a.z

#define eql(a, b) ((fabs(a.x-b.x)<=er and fabs(a.y-b.y)<=er and fabs(a.z-b.z)<=er )? 1: 0)


using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> pii;
typedef pair<lli, pii> pipii;
typedef long double ld;

struct point{
ld x, y, z;

};

point inline medium(point a, point b)
{
    point m;

    m.x=(a.x+b.x)/2.0L;
    m.y=(a.y+b.y)/2.0L;
    m.z=(a.z+b.z)/2.0L;

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

ld inline dist(point a, point b)
{
//    cout<<a.x<<endl;
    ld dx=a.x-b.x;
    ld dy=a.y-b.y;
    ld dz=a.z-b.z;

//    cout<<dx<<" "<<dy<<" "<<dz<<endl;

    return sqrtl(dx*dx+dy*dy+dz*dz);

}

int main()
{

   int t;

    scanf("%d", &t);

   for(int i=1;i<=t;i++)
   {
       point a ,b,m, p;

       scnc(a);
       scnc(b);
//       scn(p);

        cin>>p.x>>p.y>>p.z;

//       prnt(a);

       ld da=dist(a, p);
       ld db=dist(b, p);

//       cout<<da<<"da db"<<db<<endl<<endl;

       while(fabsl(da-db)>er)
       {
           m=medium(a, b);

           if(da>db)
           {
               a=st(m);
           }
           else
            b=st(m);

            da=dist(a, p);
            db=dist(b, p);



       }

       printf("Case %d: ", i);
       cout<<setprecision(6)<<(double) da<<endl;

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



