#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string x,y, z;
    map<string, string> mp;
    cin>>n>>m;

    while(n--)
    {
        cin>>x>>y;
        mp[y]=x;
    }
    while(m--)
    {
        cin>>x>>y;
        y.erase(y.end()-1);
        cout<<x<<" "<<y<<"; #"<<mp[y]<<endl;
    }


    return 0;
}
