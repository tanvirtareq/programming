#include<bits/stdc++.h>
#define er 1e-9L

#define scnc(a) cin>>a.x>>a.y>>a.z

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> pii;
typedef pair<lli, pii> pipii;
typedef long double ld;

struct point{
ld x, y, z;

};

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

    ld d2=dx*dx+dy*dy+dz*dz;

//    cout<<dx<<" "<<dy<<" "<<dz<<endl;


    if(d2>=0)
    return sqrtl(d2);

    else return sqrtl(-d2);

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
       scnc(p);
//
//       prnt(a);
//       prnt(b);
//       prnt(p);

       ld ap=dist(a, p);
       ld bp=dist(b, p);
       ld ab=dist(b, a);

       cout<<fixed<<setprecision(11);

//       cout<<ap<<" "<<bp<<" "<<ab<<endl;

       if(ab<=0)
       {
            printf("Case %d: ", i);
            cout<<setprecision(10)<<fixed<<ap<<endl;

            continue;
       }

       ld s=(ap+ab+bp)/2.0L;

//       cout<<" s "<<s<<endl;



       ld area=sqrtl(s*(s-ap)*(s-bp)*(s-ab));

//       cout<<" area  "<<area<<endl;

       ld ad=(2.0L*area)/ab;

       ld mx=max(ap, bp);

       ld x=sqrtl(mx*mx-ad*ad);

       if(x>ab)
       {
           printf("Case %d: ", i);
            cout<<setprecision(10)<<fixed<<min(ap, bp)<<endl;

            continue;



       }




       printf("Case %d: ", i);
       cout<<setprecision(10)<<fixed<<ad+er<<endl;

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

1
13 7 20 19 17 12 14 9 7

*/



