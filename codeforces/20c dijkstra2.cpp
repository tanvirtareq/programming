#include<bits/stdc++.h>
using namespace std;

// map<int, int> ft;

int ft[100005];

 int ftr(int rt)
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

    int n, m;
    cin>>n>>m;
//    map<pair<int, int> , int> mp;

int mp[n+5][n+5];

    vector<int> vx[n+10];
//    map<int, vector<int> >vx;

    while(m--)
    {
        int a, b, w;
        cin>>a>>b>>w;
//        mp[make_pair(a, b)]=w;
//        mp[make_pair(b, a)]=w;

mp[a][b]=w;
mp[b][a]=w;
        vx[a].push_back(b);
        vx[b].push_back(a);
    }

//    cout<<mp[make_pair(3, 4)]<<endl;

    unsigned dist[n+10];


    memset(dist, UINT_MAX, sizeof dist);

    dist[1]=0;

//    cout<<dist[3]<<endl;


    priority_queue<pair<long long int, int> >pq;

    pq.push(make_pair(-dist[1], 1));

    while(!pq.empty())
    {
//        cout<<pq.size()<<endl;
        pair<long long int, int> p=pq.top();
        if(p.second==n) break;
        pq.pop();

        int rt=p.second;
        int c=-p.first;

        if(dist[rt]<c) continue;

//        cout<<dist[rt]<<" "<<rt<<endl;


        for(int i=0;i<vx[rt].size();i++)
        {
            int chl=vx[rt][i];

//            cout<<rt<<" "<<chl<<endl;
            if(dist[chl]>/*mp[make_pair(rt, chl)]*/ mp[rt][chl]+dist[rt])
            {
                dist[chl]=dist[rt]+/*mp[make_pair(rt, chl)]*/ mp[rt][chl];

                pq.push(make_pair(-dist[chl], chl));
//                cout<<chl<<" "<<dist[chl]<<endl;

                ft[chl]=rt;
            }
        }

    }

//    cout<<dist[n]<<endl;

if(dist[n]==UINT_MAX)
{
    cout<<"-1"<<endl;
    return 0;
}

ftr(n);
//    int x=n;
//
//
//    vector<int> v;
//    while(x>1)
//    {
////        cout<<x<<endl;
//        v.push_back(x);
//        x=ft[x];
//    }
//
//    v.push_back(1);
//
//    reverse(v.begin(), v.end());
//
//
//    for(int i=0;i<v.size();i++)
//    {
//        cout<<v[i]<<" ";
//    }


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


6 5
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7

*/
