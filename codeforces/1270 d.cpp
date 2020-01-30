#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    map<pair<int, int> , int> mp;

    for(int i=1;i<=k+1;i++)
    {
        cout<<"?";
        for(int j=1;j<=k+1;j++)
        {
            if(j!=i) cout<<" "<<j;
        }
        cout<<endl;
        cout.flush();
        int a, b;
        cin>>a>>b;
        mp[{a, b}]++;
    }
    auto it1=mp.begin();
    auto it=it1;
    it++;
    auto it2=it;
    cout<<"! ";
    if(it2->first.second<it1->first.second)
    {
        cout<<it1->second<<endl;

    }
    else cout<<it2->second<<endl;
    cout.flush();

    return 0;
}


