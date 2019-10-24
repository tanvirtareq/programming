#include<bits/stdc++.h>

using namespace std;

bool issub(set<string>s, string x)
{
    set<string>:: iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        string st=*it;
        st=reverse(st.begin(), st.end())
        string st1;
        st.push_back()
        for(int j=0,k=i;j<x.size();j++,k++)
        {
//            cout<<c<<",,,"<<endl;
//            cout<<"("<<st[i]<<" "<<x[j]<<")"<<endl;
            if(st[k]!=x[j])
            {
                c=0;
                break;

            }
        }
        if(c==1) return 1;
    }
    return 0;

}

int main()
{
    set<pair<string, set<string> > > s;
    map<string, set<string> >mp;
    map<string,string>mp2;
    map<string, set<string> >::iterator mpit;
    set<pair<string, set<string> > >::iterator it1;
    pair<string, set<string> > p;
    set<string> stemp;
    set<string>::iterator it2;
    int n, x;
    string st;
    cin>>n;
    while(n--)
    {
        string name;
        cin>>name>>x;
        cin.ignore();
        stemp.clear();
        st=mp2[name];
        while(x--)
        {
            string nmbr;
            cin>>nmbr;
            cin.ignore();
            if(!issub(mp->second, nmbr))
            {
                st+=nmbr;
//                stemp.insert(nmbr);
                mp[name].insert(nmbr);
            }
        }
        mp2[name]=st;
//        mp.insert(make_pair(name, stemp));
    }

    cout<<mp.size()<<endl;
    for(mpit=mp.begin();mpit!=mp.end();mpit++)
    {
        cout<<mpit->first<<" ";
        cout<<mpit->second.size()<<" ";
        for(it2=mpit->second.begin();it2!=mpit->second.end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }

    return 0;
}

