#include<bits/stdc++.h>

using namespace std;

int bfs(vector<int>v[], int rt)
{
    int ans=1;
    map<int , int> mp;
    mp[rt]=1;

    queue<int>q;
    q.push(rt);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            mp[v[x][i] ]=mp[x]+1;
            q.push(v[x][i]);
            ans=max(ans, mp[v[x][i]]);
        }
    }
    return ans;

}

int main()
{
    vector<int> v[2010];
    vector<int>rt;

    int n, x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x>0)
        {
            v[x].push_back(i);
        }

        else if(x==-1)
        {
            rt.push_back(i);
        }
    }

    int ans=0;
    for(int i=0;i<rt.size();i++)
    {
//        cout<<rt[i]<<endl;
        ans=max(ans, bfs(v, rt[i]));

    }
    cout<<ans<<endl;

    return 0;
}
