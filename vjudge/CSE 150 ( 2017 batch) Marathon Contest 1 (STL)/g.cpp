#include<bits/stdc++.h>

using namespace std;


int main()
{
    int q;
    map<string, int>mp;
    cin>>q;
    while(q--)
    {
        int c, m;
        string x;
        cin>>c;
        if(c==1) {
            cin>>x>>m;
            mp[x]+=m;

        }
        else if(c==2)
        {
            cin>>x;
            mp[x]=0;
        }
        else
        {
            cin>>x;
            cout<<mp[x]<<endl;
        }

    }

    return 0;

}

