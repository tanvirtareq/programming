#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    int n, m, u, v, flag=1;
    map<int, vector<int> > mp1;
    map<int, bool>mp2;

    cin>>m>>n;
    while(n--)
    {
        cin>>u>>v;
        mp1[v].push_back(u);
    }
    while(m--)
    {
        int x;
        cin>>x;
        vector<int>::iterator it;
        for(it=mp1[x].begin();it!=mp1[x].end();it++)
        {
            if(mp2[*it]==0) flag=0;
        }
        mp2[x]=1;



    }
    if(flag==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}
/**
4 5
1 10
5 10
1 4
6 10
4 10
1  6 4 5 10
*/
