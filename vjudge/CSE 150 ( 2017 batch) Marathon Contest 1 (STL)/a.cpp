#include<bits/stdc++.h>

using namespace std;


int main()
{
    map<pair<int,int> , string> mp;
    pair<int, int> pr;

    int n, t;

    cin>>n;
    while(n--)
    {
        int x1, y1;
        string s;
        cin>>x1>>y1>>s;

        pr.first=x1;
        pr.second=y1;

        mp[pr]=s;


    }
    cin>>t;
    while(t--)
    {
        int x1, y1;
        cin>>x1>>y1;
        pr.first=x1;
        pr.second=y1;
        cout<<mp[pr]<<endl;

    }


    return 0;
}
