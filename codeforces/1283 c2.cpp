#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl;
using namespace std;

ll adj[210000], in[210000], ot[210000];
int vis[210000];
vector<ll> v[210000], asole;

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        adj[i]=x;
        in[x]=1;
        ot[i]=1;
    }

    int fc=1;
    int prv=0, st=0;
    int rt;
    for(int i=1;i<=n;i++)
    {

        if(vis[i]==0 and in[i]==0)
        {
            if(st==0) st=i;
            if(prv!=0)
            {
                adj[prv]=i;
            }
            rt=i;
            vis[rt]=1;
            while(adj[rt]!=0)
            {
                rt=adj[rt];
                vis[rt]=1;
            }
            prv=rt;
        }

    }
    adj[prv]=st;

//    for(int i=1;i<fc;i++)
//    {
//        for(int j=0;j<v[fc].size();j++)
//        {
//            asole.push_back(v[fc][j]);
//        }
//    }

    for(int i=1;i<=n;i++) cout<<adj[i]<<" ";
    cout<<endl;


    return 0;
}











