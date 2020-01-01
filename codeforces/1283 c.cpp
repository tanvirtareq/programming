#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl;
using namespace std;

ll adj[210000], in[210000], ot[210000];
int vis[210000];

int main()
{
    ll n, m;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        adj[i]=x;
        if(x!=0)
        {
            in[x]=1;
//            dbg(x);
            ot[i]=1;
        }
    }
    int j=0;

    ll rt, ch=2;
    rt=1;
    while(1)
    {
//        dbg(rt);
//        dbg(adj[rt]);
        if(vis[rt]==1) break;
        if(adj[rt]!=0) {
                 vis[rt]=1;
            rt=adj[rt];

        }

        else
        {
            int tmp=0;
            while((in[ch]!=0 or ch==rt or vis[ch]==1 ) and tmp<=3*n)
            {
                ch=(ch+1)%n+1;
                tmp++;
            }

            if(tmp>=3*n) break;

            adj[rt]=ch;
            ot[rt]=1;
            rt=ch;
            in[ch]=1;
            vis[rt]=1;
//            dbg(rt);

        }
    }

//    if(adj[rt]==0)
//    {
//        for(int i=1;i<=n;i++)
//        {
//            if(in[i]==0)
//            {
//                adj[rt]=i;
//                in[i]=1;
//                ot[rt]=1;
//                break;
//            }
//        }
//    }

    j=1;
//    dbg(j);
    for(int i=1; i<=n; i++)
    {
//        dbg(ot[i]);
        if(ot[i]==0 and adj[i]==0)
        {
            while(in[j]!=0 or j==i )
                j=(j+1)%n+1;
            ot[i]=1;
            in[j]=1;
            adj[i]=j;
//            dbg(adj[i]);
        }
    }

    for(int i=1; i<=n; i++)
        cout<<adj[i]<<" ";
    cout<<endl;


    return 0;
}










