#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int>mp;

    mp["ta"]=3;
    mp["req"]=4;
    mp["ar"]=5;

    map<string, int>::iterator i;

    for(i=mp.begin();i!=mp.end();i++)
    {

        cout<<i->first<<"="<<i->second<<endl;
    }


     return 0;
}

