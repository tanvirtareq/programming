#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int in=1; in<=t; in++)
    {
        int n;
        cin>>n;
        ii ar[n+10];
        for(int i=1; i<=n; i++)
            cin>>ar[i].first>>ar[i].second;

        int mx=1;
        for(int i=1; i<=n; i++)
        {
            map<ii, int> mp;
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                int g=__gcd(abs(ar[i].first-ar[j].first), abs(ar[i].second-ar[j].second));
                ii pr= {(ar[i].first-ar[j].first)/g, (ar[i].second-ar[j].second)/g};
                if(pr.first<0)
                {
                    pr.first=-pr.first;
                    pr.second=-pr.second;
                }
                mp[pr]++;
            }

            for(auto it=mp.begin();it!=mp.end();it++)
            {
                mx=max(mx, it->second+1);
            }
        }
        cout<<"Case "<<in<<": "<<mx<<endl;
    }
    return 0;
}

/**
2nd for loop j=i+1 dousn't work
why?


*/


