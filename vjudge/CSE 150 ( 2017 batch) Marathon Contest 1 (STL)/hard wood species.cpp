#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int>mp;
    map<string, int>::iterator it;
    int tot=0, t;

    cin>>t;
    cin.ignore();
    while(t--)
    {
//        cin.ignore();
        mp.clear();
        tot=0;
        while(1)
        {
            string s;

            getline(cin, s);
//            cout<<s<<"!"<<endl;
            if(s[0]==0) break;

            mp[s]++;
            tot++;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<" ";
            cout<<fixed<<setprecision(4)<<(float)it->second*100.0/tot<<endl;
        }
        if(t)
        cout<<endl;



    }

    return 0;
}
