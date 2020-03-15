#include<bits/stdc++.h>

#define inp(a) cin>>a.x>>a.y
#define out(a) cout<<a.x<<a.y<<endl

using namespace std;

typedef long long int li;

#define isEqual(a, b) ((a.x==b.x and a.y==b.y)?1:0)
#define distsq(a, b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct point{
li x, y;
};

point ar[100100];

li orientation(point a, point b, point c)
{
    li f=(a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);

    if(f==0) return 0;

    if(f<0) return 2;

    return 1;

}

bool cmp(point a, point b)
{
    if(orientation(ar[0], a, b)==1) return true;

    if(orientation(ar[0], a, b)==0 and distsq(ar[0], a)<distsq(ar[0], b)) return true;

    else return false;

}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {

        memset(ar, 0, sizeof ar);

        int n;
        cin>>n;

        n--;

        int j=0, mn=0;

//        point ar[n+10];

        char ch;

        point p;

        cin>>p.x>>p.y>>ch;

        if(ch=='Y')
        {
            ar[j]=p;
            j++;
        }

        while(n--)
        {
             cin>>p.x>>p.y>>ch;

            if(ch=='Y')
            {
                ar[j]=p;
                if(ar[j].x<ar[mn].x) mn=j;

                else if(ar[j].x==ar[mn].x and ar[j].y<ar[mn].y) mn=j;

                j++;


            }
        }

//           for(int i=0;i<j;i++)
//            cout<<ar[i].x<<" "<<ar[i].y<<endl;

//        cout<<mn<<endl;

        point temp=ar[0];

        ar[0]=ar[mn];

        ar[mn]=temp;

        sort(ar+1, ar+j, cmp);

        cout<<j<<endl;

        stack<point> stk;
        cout<<ar[0].x<<" "<<ar[0].y<<endl;

        for(int i=1;i<j;i++){

        if(orientation(ar[0], ar[j-1], ar[i])==0)   stk.push(ar[i]);
        else
            cout<<ar[i].x<<" "<<ar[i].y<<endl;
        }

        while(!stk.empty())
        {
            cout<<stk.top().x<<" "<<stk.top().y<<endl;

            stk.pop();

        }

    }

	return 0;
}

/**

1
5
1 1 Y
1 -1 Y
0 0 N
-1 -1 Y
-1 1 Y

1
8
0 -2 Y
1 -1 Y
2 0 Y
1 1 Y
0 2 Y
-1 1 Y
-2 0 Y
-1 -1 Y

*/


