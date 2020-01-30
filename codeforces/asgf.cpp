
#include<bits/stdc++.h>
using namespace std;
char g[100][100];
int vis[100][100],d[100][100];
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int w,h,c;
void bfs(int p,int m)
{
    queue<pair<int,int>>q;
    vis[p][m]=1;
    q.push(make_pair(p,m));
    while(!q.empty())
    {
        int f=q.front().first;
        int f1=q.front().second;
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=f+fx[k];
            int ty=f1+fy[k];
            cout<<tx<<" "<<ty<<endl;
            cout<<vis[7][2]<<endl;
            cout<<h<<" "<<w<<endl;
            if(tx>=1 && tx<=h && ty>=1 && ty<=w && g[tx][ty]!='#' && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
//                cout<<t
                c++;
//                cout<<c<<endl;
                q.push(make_pair(tx,ty));
            }
        }
    }
}
int main()
{
    vector<int> v;
    for(int i=10;i<=50;i+=5)
        v.push_back(i);

    cout<<v.size()<<endl;

    auto it=upper_bound(v.begin(), v.end(), 10);
    int tmp=(int)(it-v.begin());
    cout<<tmp<<endl;
    cout<<v[tmp-1]<<endl;

    return 0;
}
