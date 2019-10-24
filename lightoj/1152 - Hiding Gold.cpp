#include<bits/stdc++.h>

#define mx  30000
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mk make_pair
#define f(i, a, b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int  gp[1000][1000];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int vis[1000];
int N, m, n;

int dfs(int src, int tg, int par[])
{

    // cout<<src<<" "<<tg<<endl;

    if(src==tg) { return 1;}

    vis[src]=1;

    for(int i=0;i<=tg;i++)
    {
        if(vis[i]==0 and gp[src][i]>0)
        {
            par[i]=src;
            if(dfs(i, tg, par)) return 1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

    int t;
    cin>>t;
    // cout<<t<<endl;
    for(int i=1;i<=t;i++)
    {


        cin>>m>>n;

       string s[m+10];

        f(j, 0, m-1)
        {
            cin>>s[j];
        }

        int a[3]={0};
        int id[m+10][n+10];
        memset(id, -1, sizeof id);


        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(s[j][k]=='*')
                {
                    id[j][k]=a[(j+k)%2];
                    a[(j+k)%2]++;
                }
            }
        }

        N=a[0]+a[1];
        // cout<<N<<endl;

       
        clr(gp);

        int src=N+1;
        int tg=N+2;

        for(int j=0;j<a[0];j++) gp[src][j]=1;
        for(int j=0;j<a[1];j++) gp[a[0]+j][tg]=1;

        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(s[j][k]=='*' and ((j+k)%2)==0)
                {
                    for(int l=0;l<4;l++)
                    {
                        int x=j+dx[l];
                        int y=k+dy[l];

                        if(x>=0 and x<m and y>=0 and y<n and s[x][y]=='*')
                        {
                            gp[id[j][k]][a[0]+id[x][y]]=1;
                        }
                    }
                }
            }
        }

        int par[N+10];
        int ct=0;
        clr(vis);
        while(dfs(src, tg, par))
        {
            int ch=tg;
            int pr=par[ch];
            ct++;
             // cout<<ct<<endl;
            while(ch!=src){
            gp[pr][ch]-=1;
            gp[ch][pr]+=1;
            ch=pr;
            // cout<<pr<<" "<<ch<<endl;
            if(ch==src) break;
            pr=par[pr];
        }
           
            clr(vis);

        }


        cout<<"Case "<<i<<": ";
        cout<<N-ct<<endl;
    }

    return 0;
}

///  1 1 5 -5 10 2 4



