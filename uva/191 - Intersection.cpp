#include<bits/stdc++.h>

#define inp(a) cin>>a.x>>a.y
#define out(a) cout<<a.x<<a.y<<endl

using namespace std;

typedef long long int li;

#define isEqual(a, b) ((a.x==b.x and a.y==b.y)?1:0)
struct point{
li x, y;
};

li orientation(point a, point b, point c)
{
    li f=(a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);

    if(f==0) return 0;

    if(f<0) return 2;

    return 1;

}

bool isMdl(point a, point b, point m)
{
    if(m.x<=max(a.x, b.x) and m.x>=min(a.x, b.x) and m.y<=max(a.y, b.y) and m.y>=min(a.y, b.y)) return 1;

    else return 0;

}

bool isIntersect(point a1, point a2, point b1, point b2)
{



    if(isEqual(a1, a2) and isEqual(b1, b2 ))
    {
        if(isEqual(a1, b1))
        {
            return 1;
        }

        return 0;
    }

    if(isEqual(a1, a2))
    {
        if(isMdl(b1, b2, a1)) return 1;
        return 0;
    }

    if(isEqual(b1, b2))
    {
        if(isMdl(a1, a2, b1)) return 1;
        return 0;
    }

    if(isEqual(a1, b1)) return 1;
    if(isEqual(a1, b2)) return 1;
    if(isEqual(a2, b2)) return 1;
    if(isEqual(a2, b1)) return 1;

    li Oa1a2b1=orientation(a1, a2, b1);
    li Oa1a2b2=orientation(a1, a2, b2);
    li Ob1b2a2=orientation(b1, b2, a2);
    li Ob1b2a1=orientation(b1, b2, a1);

    if(Oa1a2b1==0 and Oa1a2b2==0 and Ob1b2a1==0 and Ob1b2a2==0)
    {
        if(isMdl(a1, a2, b1) or isMdl(a1, a2, b2)) return 1;
        if(isMdl(b1, b2 , a1) or isMdl(b1, b2 , a2)) return 1;

        return 0;

    }

    if(Oa1a2b1!=Oa1a2b2 and Ob1b2a2!=Ob1b2a1)
        return 1;

    return 0;

}

bool sor(point ltp,point rtp,point rbp,point lbp,point sp)
{
    if(sp.x>=ltp.x and sp.x<=rtp.x and sp.y<=ltp.y and sp.y>=lbp.y) return 1;

    return 0;

}

void swap(point *a, point *b)
{
    point temp;

    temp.x=a->x;
    temp.y=a->y;

    a->x=b->x;
    a->y=b->y;

    b->x=temp.x;
    b->y=temp.y;

    return;
}



int main()
{

    li t;

    cin>>t;

    while(t--)
    {
        point sp, ep, ltp, rbp, lbp, rtp;

        inp(sp);
        inp(ep);
        inp(ltp);
        inp(rbp);

        if(ltp.x>rbp.x or ltp.y<rbp.y)
        {
            swap(&ltp, &rbp);

        }

        lbp.x=ltp.x;
        lbp.y=rbp.y;

        rtp.x=rbp.x;
        rtp.y=ltp.y;

        li flag=0;

        if(sor(ltp, rtp, rbp, lbp, sp)) flag=1;
        if(sor(ltp, rtp, rbp, lbp, ep)) flag=1;

        if(isIntersect(sp, ep, ltp, rtp))
            flag=1;


        if(isIntersect(sp, ep, ltp, lbp))
            flag=1;

        if(isIntersect(sp, ep, rbp, rtp))
            flag=1;

        if(isIntersect(sp, ep, lbp, rbp))
            flag=1;

        if(flag==1) cout<<"T"<<endl;

        else cout<<"F"<<endl;
    }



	return 0;
}

/**
1
2 9 5 6 4 7 7 5

1
0 0 3 3 3 3 1 7

1
0 0 6 0 7 0 8 0

1
0 0 7 0 6 0 8 0

1
5 10 5 10 4 7 7 5

1
0 0 0 0 1 1 3 3


10
0 0 3 3 4 4 4 4
0 3 0 6 0 7 0 7
0 3 0 6 0 5 0 5
0 0 0 0 2 0 -2 0

2
1 1 2 2 0 4 4 0
0 18 8 12 1 1 11 11

1
5 6 5 6 4 7 7 5

*/
