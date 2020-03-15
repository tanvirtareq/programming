#include<bits/stdc++.h>

using namespace std;

int issub(set<string> s, string x)
{
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        if(*it==x) continue;
        string str;
        str.assign(it->begin()+(it->size()-x.size()), it->end());
//        cout<<str<<".."<<endl;
        if(str==x) return 1;

    }
    return 0;

}

int main()
{
    int n;
    cin>>n;
    cin.ignore();

    map<string, set<string> >mp;
    map<string, set<string> >::iterator mpit;
    while(n--)
    {
        string str;
        int t;
        cin>>str>>t;
        cin.ignore();
        set<string> s;
        s=mp[str];
        while(t--)
        {
            string x;
            cin>>x;
            cin.ignore();
            mp[str].insert(x);

        }

    }
    cout<<mp.size()<<endl;

    for(mpit=mp.begin();mpit!=mp.end();mpit++)
    {
        cout<<mpit->first<<" ";
        set<string> s;

        set<string> :: iterator sit;
        for(sit=mpit->second.begin();sit!=mpit->second.end();sit++)
        {
            if(!issub(mpit->second, *sit)) s.insert(*sit);
        }

        int x=s.size();
        cout<<x<<" ";
        for(sit=s.begin();sit!=s.end();sit++)
        {
            cout<<*sit<<" ";
        }
        cout<<endl;
    }

    return 0;
}
