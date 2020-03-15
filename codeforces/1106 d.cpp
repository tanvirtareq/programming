#include<bits/stdc++.h>


using namespace std;

typedef vector<int> vi;

vector< int > v[100100];

int n, m, x, y;

bool vis[100100];

vi p;

void bfs()
{
    int r;
    priority_queue<int, vector<int> , greater<int> >pq;

    pq.push(1);

    while(!pq.empty())
    {
        r=pq.top();
         pq.pop();
        if(vis[r]==1) continue;


        vis[r]=1;


        p.push_back(r);

        cout<<r<<" ";

        if(p.size()==n) return;

        for(int i=0;i<v[r].size();i++)
        {
            if(vis[v[r][i]]==0)
            {
                pq.push(v[r][i]);
            }

        }

    }

    return;


}


int main()
{

    cin>>n>>m;

    while(m--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);


    }

    bfs();

//    for(int i=0;i<p.size();i++)
//    {
//        cout<<p[i]<<" ";
//
//    }

    return 0;
}

/**

5 10
1 2
2 1
1 3
1 5
2 4
2 3
3 3
3 4
3 5
5 4


5 5
1 2
2 3
3 5
2 4
4 5


*/
