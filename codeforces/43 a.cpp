#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string, int> mp;
    map<string, int> ::iterator it1;
    map<string, int> ::iterator it2;
    while(n--)
    {
        string x;
        cin>>x;
        mp[x]++;

    }

    it1=mp.begin();
    if(mp.size()==2)
    it2=it1++;

    if(mp.size()==2&&it1->second<it2->second) cout<<it2->first;
    else cout<<it1->first;

    return 0;
}
