#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    while(cin>>n)
    {
        if(n==0) break;
        map<int, int> mp;
        map<int, int>:: iterator it;
        int mx=0;
        while(n--)
        {
            t=5;
            while(t--)
            {
                int x;
                cin>>x;
                mp[x]++;
                if(mp[x]>mp[mx]) mx=x;
            }
        }
        int maxm=mp[mx];
        int c=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==maxm) c++;
        }
        cout<<c<<endl;

    }

    return 0;
}

