#include<bits/stdc++.h>

using namespace std;
    map<int, vector<int> >mp;
    map<int,int>mp2;
    vector<int>v;

int col()

void func()
{
    for(int i=0;i<=2000;i++)
    {
        if(mp[i].size())
        {

        }
    }
}

int main()
{

    int m, n, q;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        if(x<y)
        {
            mp[x].push_back(y);
            mp2[x]=1;
        }
        else
        {
            mp[y].push_back(x);
            mp2[y]=1;
        }
    }
    func(mp2);

    return 0;
}
