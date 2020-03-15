
#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long int lld;

int cost[10001][10001];

class node{
    public:
        vector<int> v;
    unsigned dist;
    int prev;
    node()
    {
        dist=UINT_MAX;
        prev=0;
    }
};

node vertex[100010];

bool operator<(const node &p1,const node &p2)
{
    return p1.dist>p2.dist;
}

void dijkstra()
{
    vertex[1].dist=0;

    priority_queue<node> pq;
    pq.push(vertex[1]);

    while(pq!=empty())
    {
        node u=pq.top();

        pq.pop();

        for(int i=0;i<u.v.size();i++)
        {
            node w=u.v[i];

            if(w.dist>(u.dist+cost[u][w]))
            {
                w.dist=(u.dist+cost[u][w])
                w.prev=u;
                pq.push(w);
            }
        }
    }
}

int main()
{

    dijkstra();

//    priority_queue<node> p;
//
//    node x1;
//    x1.dist=2;
//    node x2;
//    x2.dist=1;
//    p.push(x1);
//    p.push(x2);
//
//    cout<<p.top().dist<<endl;

//    int n, m, a, b, w;
//    cin>>n>>m;
//
//
//
//    memset(d, UINT_MAX, sizeof(d));
//    d[1]=0;
//    while(m--)
//    {
//        cin>>a>>b>>w;
//        cost[a][b]=w;
        // cost[b][a]=w;
//
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }



	return 0;
}
