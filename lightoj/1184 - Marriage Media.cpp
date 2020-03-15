#include<bits/stdc++.h>

#define mx  30000
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct p
{
    int h, a, d;
};

int m, n;

int vis[110];

int gp[110][110];

int bfs(int rt,  int par[])
{
    if(rt==(m+n+1)) return 1;

    vis[rt]==1;

    for(int i=1;i<=m+n+1;i++)
    {
        if(vis[i]==0 and gp[rt][i]>0)
        {
            par[i]=rt;
            vis[i]=1;
            if(bfs(i, par)) return 1;
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
        // cout<<n<<endl;

        p men[m+10],wm[n+10];

        // vector<int> v[n+m+10];

        
        clr(gp);

        for(int j=1;j<=m;j++)
        {
            cin>>men[j].h>>men[j].a>>men[j].d;
            gp[0][j]=1;
        }


        for(int j=1;j<=n;j++)
        {
            cin>>wm[j].h;
            cin>>wm[j].a>>wm[j].d;
            gp[m+j][m+n+1]=1;
        }


        int ct=0;

        

        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(abs(men[j].h-wm[k].h)<=12 && abs(men[j].a-wm[k].a)<=5 && (men[j].d^wm[k].d)==0)
                {
                    gp[j][m+k]=1;
                    // v[m+k].pb(j);
                }
            }
        }
        // cout<<"fg1"<<endl;

        while(1)
        {
            // cout<<ct<<endl;
            int par[m+n+10];
            int x, y;
            clr(vis);
            int f=bfs(0, par);
            if(f==0) break;

            int ch=m+n+1;
            int pr=par[ch];

            int mnc=gp[pr][ch];

            while(pr!=0)
            {
                ch=pr;
                pr=par[ch];
                mnc=min(mnc, gp[pr][ch]);

            }

            ct+=mnc;

            ch=m+n+1;
            pr=par[ch];

            gp[pr][ch]-=mnc;
            gp[ch][pr]+=mnc;

            while(pr!=0)
            {
                ch=pr;
                pr=par[ch];
                gp[pr][ch]-=mnc;
                gp[ch][pr]+=mnc;

            }


        }

        cout<<"Case "<<i<<": ";
        cout<<ct<<endl;
    }

    return 0;
}

///  1 1 5 -5 10 2 4



