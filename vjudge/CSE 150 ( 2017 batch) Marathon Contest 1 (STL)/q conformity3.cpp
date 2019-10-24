#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;

        map<set<int> , int> mp;
        map<set<int> , int>:: iterator it;

        while(n--)
        {
            set<int> s;
            for(int i=0;i<5;i++)
            {
                int x;
                cin>>x;
                s.insert(x);
            }
            mp[s]++;
        }
        int mx=0;

        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>mx) mx=it->second;
        }
        int c=0;

        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==mx) c++;
        }
        cout<<c*mx<<endl;
    }

    return 0;
}
