#include<bits/stdc++.h>

using namespace std;

map<int, int> mp;
map<int, int> vis;
int c=0;
int dfs(vector<int>v[], int rt, int chk, int ans, int ok)
{
//    cout<<rt<<"   "<<ans<<endl;
    if(vis[rt]==1) return ans;

    vis[rt]=1;

    if(mp[rt]==0) chk=0;
    else
    chk=chk+1;

//    cout<<rt<<"chj "<<chk<<endl;
    if(chk>ok)
    {
//        cout<<" chk   "<<chk<<endl;
        return ans;
    }

    if(v[rt].size()==1&&c==1)
    {

        if(chk>ok)
        {
//            cout<<rt<<"   "<<ans<<endl;
            return ans;
        }

        else
        {
//            cout<<rt<<"   "<<ans+1<<endl;
            return ans+1;
        }
    }
    c=1;

    for(int i=0;i<v[rt].size();i++)
    {
//        if(rt!=v[rt][i])
        ans=dfs(v, v[rt][i], chk, ans, ok);
//        cout<<rt<<"   "<<ans<<endl;
    }
//     cout<<rt<<"   "<<ans<<endl;
    return ans;
}

int main()
{
    vector<int> v[100010];

    int n, m, x, t;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        mp[i]=x;
    }

    for(int i=1;i<n;i++)
    {
        int y;
        cin>>x>>y;
//        if(x!=y)
        v[x].push_back(y);
        v[y].push_back(x);

    }

    int ans=dfs(v, 1, 0, 0, m);
    cout<<ans<<endl;

    return 0;
}

/**
7 3
1 1 1 1 1 0 1
1 2
1 3
2 4
3 5
5 6
6 7
*/

