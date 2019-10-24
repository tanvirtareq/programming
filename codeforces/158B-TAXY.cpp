#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int>mp;
    int n, a, ans;

    cin>>n;

    while(n--)
    {
        cin>>a;
        mp[a]++;

    }
    int two=mp[2]/2;
    mp[2]=mp[2]%2;

    int onethree;
    if(mp[1]<mp[3])
    {
        onethree=mp[1];
        mp[3]=mp[3]-mp[1];
        mp[1]=0;
        ans=mp[4]+mp[3]+two+mp[2]+onethree;
    }

    else
    {
        onethree=mp[3];
        mp[1]=mp[1]-mp[3];
        mp[3]=0;
        int onefour=mp[1]/4;
        int onetwo=ceil((float)(mp[2]*2+mp[1]%4)/4);
        ans=onefour+onetwo+onethree+two+mp[4];

    }
    cout<<ans<<endl;

    return 0;
}
