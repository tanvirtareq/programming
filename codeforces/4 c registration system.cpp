#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<string , int> mp;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(mp[s]==0)
        {
            cout<<"OK"<<endl;
            mp[s]++;
        }
        else
        {
            cout<<s<<mp[s]<<endl;
            mp[s]++;
        }

    }

    return 0;
}
