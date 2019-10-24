#include<bits/stdc++.h>

using namespace std;




bool bfs(vector<int>v[], int r)
{
    map<int, bool> mp;
    map<int, bool> mp1;
    queue<int>q;
    mp[r]=0;
    q.push(r);
    mp1[r]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            int y=v[x][i];
//            cout<<x<<y<<endl;
//            if(mp1[y] and mp[y]==mp[x]) cout<<"bgf"<<endl;
            if(mp1[y]==1 and mp[y]==mp[x]) return false;
            if(mp1[y]!=1)
            {


            mp[y]=!mp[x];
            mp1[y]=1;
            q.push(y);
            }

        }

    }
    return true;
}

int main()
{
    int n, e;
    while(cin>>n)
    {
        if(n==0) return 0;
        cin>>e;
        vector<int>v[210];
//        mp.clear();
        while(e--)
        {
            int x, y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(bfs(v, 0))
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else cout<<"NOT BICOLORABLE."<<endl;

    }

    return 0;
}
