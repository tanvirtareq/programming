#include<bits/stdc++.h>
#define ii pair<int, int>
#define Mxr

using namespace std;



char ar[1100][1100];
int r,mn, c, vis[1100][1100], f[1100][1100];
ii rt1, rt2;
int dx[]= {0, 1, 0, -1};
int dy[]= {1, 0, -1, 0};
int f2[1100][1100];

void prn(int f[1100][1100], int r, int c)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void bfs1(int x, int y, int tt)
{
    vis[x][y]=tt;
    f[x][y]=0;
    queue<ii> q;
    q.push({x, y});
    while(!q.empty())
    {
        ii rt=q.front();
        q.pop();
        int ct=f[rt.first][rt.second];
        for(int i=0; i<4; i++)
        {
            int nx=rt.first+dx[i];
            int ny=rt.second+dy[i];
            if(1<=nx and nx<=r and 1<=ny and ny<=c and vis[nx][ny]!=tt
               and ar[nx][ny]!='#' and f[nx][ny]>ct+1)
            {
                vis[nx][ny]=tt;
                f[nx][ny]=min(f[nx][ny], ct+1);
                q.push({nx, ny});
            }
        }
    }
    return;
}

int bfs2(int x, int y, int tt)
{
    if(x==1 or x==r or y==1 or y==c)
    {
        mn=1;
        return 1;
    }
    mn=INT_MAX;
    vis[x][y]=tt;N
    f2[x][y]=0;
//    cout<<x<<" "<<y<<endl;
//    f2[]
    queue<ii> q;
    q.push({x, y});
    while(!q.empty())
    {
        ii rt=q.front();
        q.pop();
        if(f2[rt.first][rt.second]>=f[rt.first][rt.second])
        {
            return 0;
        }
        int ct=f2[rt.first][rt.second];
        for(int i=0; i<4; i++)
        {
            int nx=rt.first+dx[i];
            int ny=rt.second+dy[i];
            if(1<=nx and nx<=r and 1<=ny and ny<=c and vis[nx][ny]!=tt
               and ar[nx][ny]!='#' and f[nx][ny]>ct+1 and f2[nx][ny]>ct+1)
            {
                vis[nx][ny]=tt;
                f2[nx][ny]=ct+1;
                q.push({nx, ny});
                if(nx==1 or nx==r or ny==1 or ny==c) {
                        mn=min(mn, f2[nx][ny]+1);
                        return 1;
                }
            }

        }
    }
    return 0;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        vector<ii> v;
        cin>>r>>c;
        for(int i=1;i<r+10;i++)
        {
            for(int j=1;j<c+10;j++)
            {
                f[i][j]=INT_MAX;
                ar[i][j]=0;
                vis[i][j]=0;
                f2[i][j]=INT_MAX;
            }
        }

        for(int i=1; i<=r; i++)
        {
            cin.ignore();
            for(int j=1; j<=c; j++)
            {
                cin>>ar[i][j];
                if(ar[i][j]=='F')
                    v.push_back({i, j});
                if(ar[i][j]=='J')
                    rt2= {i, j};
            }

        }

        for(int i=0;i<v.size();i++)
        {
//             memset(vis, 0, sizeof vis);
             bfs1(v[i].first, v[i].second, i+1);
        }

//        prn(f, r, c);
//        memset(vis, 0, sizeof vis);
        int ans=bfs2(rt2.first, rt2.second, v.size()+5);

//        prn(f2, r, c);
        if(ans)
        {
            cout<<mn<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}

/**

1
1 1
J

1
2 2
J.
..

1
4 4
####
F#J#
F..#
....

1
5 7
#######
FJ..#..
F.#..##
FFF#.##
.......

1
5 7
#######
FJ..#..
F.#..##
FFF#.##
...#...


1
9 9
.........
.#####.#.
.#...#.#.
.#.#.#.#.
.#.#.#.#.
.#.#.#.#.
.#J#...#.
.#######.
F........


1
9 9
.........
.#####.#.
.#...#.#.
.#.#.#.#.
.#.#.#.#F
.#.#.#.#.
.#J#...#.
.#######.
F........

*/
