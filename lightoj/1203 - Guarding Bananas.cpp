#include<bits/stdc++.h>

#define inp(a) scanf("%d%d", &a.x, &a.y)
#define out(a) cout<<a.x<<a.y<<endl
#define sci(a) scanf("%d", &a)
#define clr(a) memset(a, 0, sizeof a)

using namespace std;

typedef long long int li;

#define isEqual(a, b) ((a.x==b.x and a.y==b.y)?1:0)
#define distsq(a, b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

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

point ar[10010];

bool cmp(point a, point b)
{
    if(orientation(ar[0], a, b)==1) return true;

    if(orientation(ar[0], a, b)==0 and distsq(ar[0], a)>distsq(ar[0], b)) return true;

    else return false;

}

    stack<point> st;
point nextToTop()
{
    point ret=st.top();
    st.pop();
    point r=st.top();

    st.push(ret);

    return r;

}



int main()
{
    int t;
    sci(t);

    for(int i=1;i<=t;i++)
    {
        clr(ar);

        int n;

        sci(n);

        if(n<3)
        {
            printf("Case %d: 0\n", i);

            continue;
        }

        inp(ar[0]);

        int mn=0;

        for(int j=1;j<n;j++)
        {
            inp(ar[i]);

            if(ar[i].x<ar[mn].x) mn=i;

            else if(ar[i].y==ar[mn].y and ar[i].x<ar[mn].x)
            mn=i;

        }

        point temp=ar[mn];
        ar[mn]=ar[0];
        ar[0]=temp;

        sort(ar+1, ar+n, cmp);

        for(int i=0;i<n;i++)
        {
            out(ar[i]);
        }

        int m=1;

        for(int i=2;i<n;)
        {
//        out(ar[0])

//        cout<<orientation(ar[0], ar[i], ar[m])<<endl;

            while(orientation(ar[0], ar[i], ar[m])==0)
            {
                i++;
//            cout<<i<<endl;
            }

//        cout<<i<<endl;
            ar[++m]=ar[i];
            i++;
        }

        st.push(ar[0]);
        st.push(ar[1]);

        for(int i=2;i<=m;i++)
        {
            while(orientation(nextToTop(), st.top(), ar[i])==2)
            {
                st.pop();
            }
            st.push(ar[i]);
        }

        point lst=st.top();
        st.pop();

        point pvlst=st.top();
        st.pop();
        point x=st.top();
        st.pop();

        point a=lst;
        point b=pvlst;
        point c=x;

        double mnans=acos((double)((c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y))/(double)sqrt(distsq(b, c)*distsq(a,b)));

        while(!st.empty())
        {
            a=b;
            b=c;
            c=st.top();

            st.pop();

            double mntmp=acos((double)((c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y))/(double)sqrt(distsq(b, c)*distsq(a,b)));

            mnans=min(mntmp, mnans);
        }

        a=b;
        b=c;
        c=lst;

        double mntmp=acos((double)((c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y))/(double)sqrt(distsq(b, c)*distsq(a,b)));

        mnans=min(mntmp, mnans);

        a=b;
        b=c;
        c=pvlst;

        mntmp=acos((double)((c.x-b.x)*(a.x-b.x)+(c.y-b.y)*(a.y-b.y))/(double)sqrt(distsq(b, c)*distsq(a,b)));

        mnans=min(mntmp, mnans);

        printf("Case %d: %.6lf\n", i, mnans);


    }


	return 0;
}


