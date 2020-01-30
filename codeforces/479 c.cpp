#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ar[10000][2], dp[100000][2];
 int n;
int cmp(pair<int, int> p, pair<int, int> q)
{
    if(p.first==q.first) return p.second<q.second;
    return p.first<q.first;
}
int dpf(int st, int tk)
{
    if(st>=n) return ar[st-1][tk];
    if(dp[st][tk]!=-1) return dp[st][tk];

    int p=INT_MAX-10, q=INT_MAX-10;
    if(st==0)
    {
        p=dpf(st+1, 0);
        q=dpf(st+1, 1);
    }
    else
    {
        if(ar[st][0]>=ar[st-1][tk])
            p=dpf(st+1, 0);
        if(ar[st][1]>=ar[st-1][tk])
            q=dpf(st+1, 1);
//        if(ar[st][0]!=ar[st-1][tk]);
//        if(ar[st][1]!=ar[st-1][tk]);
    }
    return dp[st][tk]=min(p, q);
}
int main()
{

    cin>>n;
    vector<pair<int, int> > v(n);
    for(auto &it:v) cin>>it.first>>it.second;
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<n;i++)
    {
        ar[i][0]=v[i].first;
        ar[i][1]=v[i].second;
    }
    memset(dp, -1, sizeof dp);
    cout<<dpf(0, 0)<<endl;

    return 0 ;
}


