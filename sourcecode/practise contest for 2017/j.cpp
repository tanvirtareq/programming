#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> mp;
    map<int, int>::iterator it;

    int a, b=0, n, k;

    cin>>n>>k;

    while(n--)
    {
        cin>>a;
        mp[a]=1;
    }

    for(it=mp.begin();it!=mp.end();it++)
    {
        int temp1, temp2;
        temp1=it->first;
        if(mp[k-temp1]==1) b++;

        mp[temp1]=0;

    }

    cout<<b<<endl;

    return 0;
}


