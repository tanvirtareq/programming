#include<bits/stdc++.h>
#define pii pair<llu, llu>
#define inf ULLONG_MAX
//typedef pair<int, int> pii;
typedef long long unsigned llu;
typedef long long int lld;
using namespace std;

// map<int, int> ft;

llu ft[100001];

 llu ftr(llu rt)
 {
     if(rt==1)
     {
         cout<<rt<<" ";
         return rt;
     }

     ftr(ft[rt]);
     cout<<rt<<" ";
 }

int main()
{
//    cout<<UINT_MAX<<endl;

    llu n, m;
    cin>>n>>m;

    vector<llu> edge[n+1], cost[n+1];

    llu d[n+5];
//    cout<<d[7]<<endl;

//    cout<<sizeof d<<endl;
    memset(d, inf, sizeof d);

//    cout<<d[7]<<endl;


    while(m--)
    {
        llu a, b, w;
        cin>>a>>b>>w;
        edge[a].push_back(b);
        cost[a].push_back(w);
        edge[b].push_back(a);

        cost[b].push_back(w);
//        cout<<sizeof(cost)<<endl;

    }

//    cout<<sizeof(cost)/n<<endl;



//    cout<<sizeof(cost)<<endl;

    priority_queue<pii,vector<pii>, greater<pii> >pq;
    d[1]=0;

    pq.push(pii(0, 1));
//    pq.push(pii(2, 3));

//    cout<<sizeof(pq)<<endl;

    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();

        llu rt=p.second;
        if(rt==n) break;
        llu dist=p.first;
//        cout<<rt<<" "<<dist<<endl;

        for(llu i=0;i<edge[rt].size();i++)
        {
            llu x=dist+cost[rt][i];
//            cout<<" cst"<<cost[rt][i]<<endl;
//            cout<<"I"<<i<<endl;


            llu chl=edge[rt][i];
//            cout<<chl<<endl;

//            cout<<"cmp"<<x<<" "<<d[chl]<<endl;

            if(x<d[chl])
            {
                d[chl]=x;
                pq.push(pii(d[chl], chl));
//                cout<<"push"<<chl<<" "<<d[chl]<<endl;
                ft[chl]=rt;
            }

        }

    }


if(d[n]==inf)
{
    cout<<"-1"<<endl;
    return 0;
}

ftr(n);

    return 0;
}

/**

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1


9 8
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
7 8 9
8 9 10

4 3
1 2 3
2 3 4
3 4 5

*/

