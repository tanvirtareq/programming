#include<bits/stdc++.h>

using namespace std;

bool issub(string st, string x)
{
    for(int i=0;i<st.size();i++)
    {
        int c=1;
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
        st.clear();
        while(x--)
        {
            string nmbr;
            cin>>nmbr;
            cin.ignore();
            if(!issub(st, nmbr))
            {
                st+=nmbr;
                stemp.insert(nmbr);
            }
        }
        s.insert(make_pair(name, stemp));
    }

    cout<<s.size()<<endl;
    for(it1=s.begin();it1!=s.end();it1++)
    {
        cout<<it1->first<<" ";
        cout<<it1->second.size()<<" ";
        for(it2=it1->second.begin();it2!=it1->second.end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }

    return 0;
}
