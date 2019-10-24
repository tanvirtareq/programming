#include<bits/stdc++.h>

using namespace std;

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
    return ;

}

int bfs(int s, int t)
{

    queue<int> q;
    q.push(s);
    int y=0;
    map<int, int> mp;
//    mp[s]++;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x>t) return x-t+mp[x];
        if(x==t) return mp[x];
        if(t==2*x||t==x-1) return mp[x]+1;

        if(mp[2*x]==0)
        {

            mp[2*x]=mp[x]+1;
            q.push(2*x);
        }
//        if(mp[x-1]==0)
//        {
//            mp[x-1]=mp[x]+1;
//            q.push(x-1);
//        }
//
//


//        print(q);

    }

}

int main()
{
    int n, m;
    cin>>n>>m;

    int ans=bfs(n, m);
    cout<<ans<<endl;

    return 0;
}
