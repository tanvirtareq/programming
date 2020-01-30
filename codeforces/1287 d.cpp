#include<bits/stdc++.h>
#define ll long long


using namespace std;
int rt, t;
queue<int> q;
vector<int> adj[2100];
int par[2100], c[2100], nm[2100];

void dfs(int r, int p)
{
    if(adj[r].size()<=1)
    {
        q.push(r);
        return;
    }
    for(int i=0;i<adj[r].size();i++)
        if(adj[r][i]!=p) dfs(adj[r][i], r);
}

int rec(int r)
{
    if(par[r]==0)
    {
        if(c[r]<=0)
        {
            if(nm[r]!=t and nm[r]!=0) return nm[r];
            else nm[r]=t;
            return 0;
        }
        c[r]--;
        if(c[r]==0) q.push(r);
        return 0;

    }
//    if(r==0) return 1;
    if(c[r]<=0)
    {
        if(nm[r]!=t and nm[r]!=0) return nm[r];
        else nm[r]=t;
        int x=rec(par[r]);
//        if(x==-1) return -1;

        return x;
    }

    c[r]--;
    if(c[r]==0) q.push(r);
    int x=rec(par[r]);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    t=1;
    for(int i=1;i<=n;i++)
    {
        int x, y;
        cin>>x>>y;
        par[i]=x;
        c[i]=y;
        if(x!=0){
        adj[i].push_back(x);
        adj[x].push_back(i);
        }
        else rt=i;
        nm[i]=0;
        if(y==0) q.push(i);

//        cout<<i<<" "<<x<<" "<<y<<endl;

    }

//    dfs(rt, -1);
//    cout<<endl<<endl;
    int ct=0;

    while(!q.empty())
    {
        ct++;
        int r=q.front();
        q.pop();
        if(nm[r]!=0) continue;
        nm[r]=t;
//        cout<<r<<" "<<t<<endl;
        int x=rec(par[r]);
//        cout<<x<<endl;
//        if(x!=0) nm[r]=x;
//        if(x!=0 and x<t) {
//            cout<<"NO"<<endl;
//            return 0;
//        }
        t++;

    }

    if(ct<n)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<nm[i]<<" ";
    }



    return 0;
}



