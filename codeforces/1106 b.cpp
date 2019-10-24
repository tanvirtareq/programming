#include<bits/stdc++.h>

//#define vector<int> vi;

using namespace std;

typedef long long int li;

typedef pair<li,li> pii;


int main()
{

    li n, m;
    cin>>n>>m;

    li a[n+10], c[n+10];

    priority_queue< pii, vector< pii > , greater< pii > > pq;

    for(li i=1;i<=n;i++)
        cin>>a[i];

    for(li i=1;i<=n;i++){
        cin>>c[i];
        pq.push(make_pair(c[i], i));
    }

//    cout<<pq.top().second<<endl;


    while(m--)
    {
        li d=0;

        li x, y;

        cin>>x>>y;

        if(y<=a[x])
        {
            d=c[x]*y;
            a[x]=a[x]-y;
            y=0;
            cout<<d<<endl;
        }

        else if(y>a[x])
        {
            d=c[x]*a[x];
            y=y-a[x];
            a[x]=0;

            while(y>0 and !pq.empty())
            {
                li indx=pq.top().second;

                if(a[indx]<=0)
                {
                    pq.pop();
                    continue;
                }
                else if(y<=a[indx])
                {
                    d+=c[indx]*y;

                    a[indx]=a[indx]-y;
                    y=0;
//                    cout<<d<<endl;
                    break;

                }

                 else if(y>a[indx])
                 {
                    d+=c[indx]*a[indx];
                    y=y-a[indx];
                    a[indx]=0;
                    pq.pop();
                    continue;

                 }

            }
            if(y<=0)
            cout<<d<<endl;

            else cout<<0<<endl;

        }



    }

    return 0;
}

/**

8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 8
1 4
4 7
3 4
6 10


*/
