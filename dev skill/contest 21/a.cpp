#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned lld;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int , int> mp;
        map<int , int>::iterator it;
        int n;
        cin>>n;
        while(n--)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        int ans;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==2) ans=it->first;
        }
        cout<<ans<<endl;

    }

    return 0;
}
/**

364269800189924
33
*/



