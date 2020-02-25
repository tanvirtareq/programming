#include<bits/stdc++.h>

using namespace std;

const long double INF = 1e100;
const long double EPS = 1e-15;

struct PT
{
    long double x, y;
    PT() {}
    PT(long double x, long double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (long double c) const
    {
        return PT(x*c, y*c);
    }
    PT operator / (long double c) const
    {
        return PT(x/c, y/c);
    }

    bool operator == (const PT &p) const
    {
        if(fabs(x-p.x)<=EPS and fabs(y-p.y)<=EPS)
            return true;
        return false;
    }
};

double Q_rsqrt( double number ){
   int i;
   double x2, y;
   const double threehalfs = 1.5F;

   x2 = number * 0.5F;
   y   = number;
   i   = * ( int * ) &y;   // evil floating point bit level hacking
   i   = 0x5f3759df - ( i >> 1 ); // what the fuck?
   y   = * ( double * ) &i;
   y   = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
   y   = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

   return y;
}

long double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}

long double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

long double dist2D_sqr(PT p, PT q)
{
    return dot(p-q, p-q);
}

long double abs(PT a)
{
    return sqrt(dot(a, a));
}

long double clamp(long double a, long double l, long double r)
{
    if(a>r) return r;
    if(a<l) return l;
    return a;
}

long double angle(PT v, PT w)
{
    return acos(clamp(dot(v,w)/Q_rsqrt(dot(v, v)*dot(w, w)), -1.0, 1.0));
}

vector<PT> CircleLineIntersection(PT a, PT b, PT c, long double r)
{
    vector<PT>ret;
    b=b-a;
    a=a-c;

    long double A=dot(b, b);
    long double B=dot(a, b);
    long double C=dot(a, a)-r*r;
    long double D=B*B-A*C;

    if(D<-EPS)
        return ret;

    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);

    if(D>EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);

    return ret;
}


/// Computes the area of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion

long double ComputeSignedArea(const vector<PT>p)
{
    long double area=0.0;
    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }

    return area/2.0;
}

long double ComputeArea(const vector<PT>p)
{
    return fabs(ComputeSignedArea(p));
}


int pbaire(long double r, PT a)
{
    if(r*r+EPS<(a.x*a.x+a.y*a.y))
        return 1;
    return 0;
}

void chng(long double r, vector<PT> &v)
{
    PT c=PT(0, 0);
    vector<PT> rt;
    rt=CircleLineIntersection(v[0], v[1], c, r);

    if((pbaire(r, v[0])*pbaire(r, v[1])))
    {

        int flg=0;
        if(rt.size()>1)
        {
            if(v[0].x-EPS<=rt[1].x && rt[1].x<=v[1].x+EPS)
                flg=1;
        }

        if(rt.size()>0)
        {
            if(v[0].x-EPS<=rt[1].x && rt[1].x<=v[1].x+EPS)
                flg=1;
        }

        if(flg==0)
        {
            if(v[0].x-EPS<=0 && v[1].x+EPS>=0)
            {
                v[0].y=-r+EPS;
                v[1].y=-r+EPS;
            }
            else if(v[0].x+EPS>0)
            {
                vector<PT> tmp=CircleLineIntersection(v[0], v[3], c, r);

                if(tmp.size()>1)
                {
                    v[1].y=v[0].y=min(tmp[0].y, tmp[1].y);
                }
                else
                {
                    v[1].y=v[0].y=tmp[0].y;
                }
            }

            else if(v[1].x-EPS<0)
            {
                vector<PT> tmp=CircleLineIntersection(v[1], v[2], c, r);

                if(tmp.size()>1 && tmp[0].y>tmp[1].y)
                {
                    v[1].y=v[0].y=tmp[1].y;
                }
                else
                {
                    v[1].y=v[0].y=tmp[0].y;
                }
            }
        }


    }
    rt=CircleLineIntersection(v[1], v[2], c, r);

    if((pbaire(r, v[1])*pbaire(r, v[2])))
    {
        int flg=0;
        if(rt.size()>1)
        {
            if(v[1].y-EPS<=rt[1].y && rt[1].y<=v[2].y+EPS)
                flg=1;
        }

        if(rt.size()>0)
        {
            if(v[1].y-EPS<=rt[1].y && rt[1].y<=v[2].y+EPS)
                flg=1;
        }

        if(flg==0)
        {
            if(v[1].y-EPS<=0 && v[2].y+EPS>=0)
            {
                v[1].x=r-EPS;
                v[2].x=r-EPS;
            }
            else if(v[1].y+EPS>0)
            {
                vector<PT> tmp=CircleLineIntersection(v[0], v[1], c, r);

                if(tmp.size()>1 && tmp[0].x<tmp[1].x)
                {
                    v[1].x=v[2].x=tmp[1].x;
                }
                else
                {
                    v[1].x=v[2].x=tmp[0].x;
                }
            }

            else if(v[2].y-EPS<0)
            {
                vector<PT> tmp=CircleLineIntersection(v[2], v[3], c, r);

                if(tmp.size()>1 && tmp[0].x<tmp[1].x)
                {
                    v[1].x=v[2].x=tmp[1].x;
                }
                else
                {
                    v[1].x=v[2].x=tmp[0].x;
                }
            }
        }


    }


    rt=CircleLineIntersection(v[2], v[3], c, r);

    if((pbaire(r, v[2])*pbaire(r, v[3])))
    {
        int flg=0;
        if(rt.size()>1)
        {
            if(v[3].x-EPS<=rt[1].x && rt[1].x<=v[2].x+EPS)
                flg=1;
        }

        if(rt.size()>0)
        {
            if(v[3].x-EPS<=rt[0].x && rt[0].x<=v[2].x+EPS)
                flg=1;
        }

        if(flg==0)
        {
            if(v[3].x-EPS<=0 && v[2].x+EPS>=0)
            {
                v[2].y=r-EPS;
                v[3].y=r-EPS;
            }
            else if(v[3].x+EPS>0)
            {
                vector<PT> tmp=CircleLineIntersection(v[0], v[3], c, r);

                if(tmp.size()>1 && tmp[0].y<tmp[1].y)
                {
                    v[3].y=v[2].y=tmp[1].y;
                }
                else
                {
                    v[3].y=v[2].y=tmp[0].y;
                }
            }

            else if(v[2].x-EPS<0)
            {
                vector<PT> tmp=CircleLineIntersection(v[2], v[1], c, r);

                if(tmp.size()>1 && tmp[0].y<tmp[1].y)
                {
                    v[3].y=v[2].y=tmp[1].y;
                }
                else
                {
                    v[3].y=v[2].y=tmp[0].y;
                }
            }
        }


    }

//    for(int i=0; i<v.size(); i++)
//    {
//        cout<<v[i].x<<" "<<v[i].y<<endl;
//    }

    rt=CircleLineIntersection(v[3], v[0], c, r);

//    cout<<rt.size()<<endl;
//    cout<<rt[0].x<<" "<<rt[0].y<<endl;
//    cout<<rt[1].x<<" "<<rt[1].y<<endl;

    if((pbaire(r, v[3])*pbaire(r, v[0])))
    {
        int flg=0;
        if(rt.size()>1)
        {
            if(v[0].y-EPS<=rt[1].y && rt[1].y<=v[3].y+EPS)
                flg=1;
        }

        if(rt.size()>0)
        {
            if(v[0].y-EPS<=rt[1].y && rt[1].y<=v[3].y+EPS)
                flg=1;
        }

//        else if(rt.size()==0)
//            flg=1;

        if(flg==0)
        {
//            cout<<rt.size()<<endl;
            if(v[0].y-EPS<=0 && v[3].y+EPS>=0)
            {
                v[0].x=-r+EPS;
                v[3].x=-r+EPS;
            }
            else if(v[0].y+EPS>0)
            {
                vector<PT> tmp=CircleLineIntersection(v[0], v[1], c, r);

                if(tmp.size()>1 && tmp[0].x>tmp[1].x)
                {
                    v[3].x=v[0].x=tmp[1].x;
                }
                else
                {
                    v[3].x=v[0].x=tmp[0].x;
                }
            }

            else if(v[3].y-EPS<0)
            {
                vector<PT> tmp=CircleLineIntersection(v[3], v[2], c, r);

//            cout<<tmp[0].x<<endl;

                if(tmp.size()>1 && tmp[0].x>tmp[1].x)
                {
                    v[3].x=v[0].x=tmp[1].x;
                }
                else
                {
                    v[3].x=v[0].x=tmp[0].x;
                }
            }
        }


    }

}


long double calcu(long double r, vector<PT> &v)
{
    long double res=0;

    for(int i=0; i<v.size(); i++)
    {
        if(pbaire(r, v[i]))
        {
            PT a=v[(i-1+v.size())%v.size()];
            PT b=v[i];
            PT c=v[(i+1)%v.size()];

//            cout<<a.x<<" "<<a.y<<endl;
//            cout<<b.x<<" "<<b.y<<endl;
//            cout<<c.x<<" "<<c.y<<endl;


            PT ori=PT(0, 0);

            vector<PT> rt;

            PT p1, p2;

            rt=CircleLineIntersection(a, b, ori, r);
//            cout<<rt.size()<<endl;

            if(rt.size()>1 && dist2D_sqr(b, rt[0])>dist2D_sqr(b, rt[1]))
                p1=rt[1];
            else
                p1=rt[0];

            rt=CircleLineIntersection(b, c, ori, r);


            if(rt.size()>1 && dist2D_sqr(b, rt[0])>dist2D_sqr(b, rt[1]))
                p2=rt[1];
            else
                p2=rt[0];

//            cout<<p1.x<<" "<<p1.y<<endl;
//            cout<<p2.x<<" "<<p2.y<<endl;


            vector<PT> v1;
            v1.push_back(PT(0, 0));
            v1.push_back(p1);
            v1.push_back(v[i]);
            v1.push_back(p2);

            long double fullare=ComputeArea(v1);



            long double ang=angle(p1, p2);


            long double pcir=0.5*r*r*ang;

//            cout<<fullare<<" "<<pcir<<endl;

            res+=fullare-pcir;
//            cout<<res<<endl;

        }
    }

//    cout<<res<<endl;
//    cout<<ComputeArea(v)<<endl;
//
//    cout<<fabs(v[0].x-v[1].x)*fabs(v[1].y-v[2].y)<<endl;

    return ComputeArea(v)-res;
}

int baire(long double r, vector<PT> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(!pbaire(r, v[i]))
            return 0;
    }

//    if(v[0].y+EPS>r || v[1].x-EPS<-r || v[2].y-EPS<-r || v[3].x+EPS>r)
//        return 1;

    if(v[0].y-EPS>r || v[1].x+EPS<-r || v[2].y+EPS<-r || v[3].x-EPS>r)
        return 1;

    if(v[0].x*v[1].x-EPS<=0 || v[1].y*v[2].y-EPS<=0 || v[2].x*v[3].x-EPS<=0 || v[3].y*v[0].y-EPS<=0)
        return 0;

    return 1;
}

int main()
{

//
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;

//    for(int i=1;i<=t;i++)
//    {
//        long double x, y, r, x1, y1, x2, y2;
//        cin>>x>>y>>r>>x1>>y1>>x2>>y2;
//        if(i==122)
//        {
//            cout<<" ad"<<endl;
//            cout<<x<<" "<<y<<" "<<r<<endl;
//            cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
//            cout<<endl<<endl;
//        }
//    }

    for(int in=1; in<=t; in++)
    {
        long double x, y, r, x1, y1, x2, y2;
        cin>>x>>y>>r>>x1>>y1>>x2>>y2;

        long double cx=0, cy=0;
        x1-=x;
        x2-=x;
        y1-=y;
        y2-=y;

        vector<PT> v;
        v.push_back(PT(x1, y1));
        v.push_back(PT(x2, y1));
        v.push_back(PT(x2, y2));
        v.push_back(PT(x1, y2));
//
//        for(int i=0; i<v.size(); i++)
//        {
//            cout<<v[i].x<<" "<<v[i].y<<endl;
//        }

        cout<<"Case "<<in<<": ";
        if(baire(r, v))
        {
            cout<<0.00000000<<endl;
        }

        else
        {
            chng(r, v);


//            for(int i=0; i<v.size(); i++)
//            {
//                cout<<v[i].x<<" "<<v[i].y<<endl;
//            }

//            cout<<ComputeArea(v)<<endl;

            if(v[0]==v[1] || v[1]==v[2] || v[2]==v[3] || v[3]==v[0])
            {
                cout<<0.00000000<<endl;
            }
            else
                cout<<setprecision(8)<<fixed<<calcu(r, v)<<endl;
        }

    }

    return 0;
}


/**
1
76 88 68
85 133 158 154


1
36 57 96
129 48 173 177

1
104 170 131
7 14 94 48


1
6 27 168
89 133 165 153

1
112 47 61
25 34 67 128

1
154 47 158
87 61 156 179

1
109 74 56
75 120 76 182

1
154 101 119
14 5 82 142

1
81 39 117
86 72 149 188

*/

