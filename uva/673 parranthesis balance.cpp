#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
         stack<char>st;
         bool chk=true;
        string x;

//        cout<<x.size()<<endl;

        getline(cin, x);
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='(' or x[i]=='[')
                st.push(x[i]);

            if(x[i]==')')
            {
                if(st.empty() or  st.top()!='(')
                {
//                    cout<<i<<endl;
                    chk=false;
                    break;
                }
                else
                    st.pop();
            }
            if(x[i]==']')
            {
                if(st.empty() or  st.top()!='[')
                {
//                    cout<<i<<endl;
                    chk=false;
                    break;
                }
                else
                    st.pop();
            }
        }

//        if(x.size()==0) cout<<"Yes"<<endl;
//        if(st.empty()) cout<<"har"<<endl;
        if(chk==false or !st.empty()) cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;

    }

    return 0;
}

/**
3
([])
(([()])))
([()[]()])()
*/
