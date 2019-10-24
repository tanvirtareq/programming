#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    map<char , int> prec;
    prec['+']=1;
    prec['-']=2;
    prec['*']=3;
    prec['/']=4;
    prec['^']=5;

    while(t--)
    {
        string x;

        cin>>x;
        x.push_back(')');

        stack<char> st;
        st.push('(');

        string p;

        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='(')
                st.push(x[i]);

            else if(x[i]==')')
            {
                while(st.top()!='(')
                {
                    p.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(prec[x[i]]==0)
                p.push_back(x[i]);

            else{
               while(prec[st.top()]>=prec[x[i]])
               {
                   p.push_back(st.top());
                   st.pop();
               }
               st.push(x[i]);

            }
        }

        cout<<p<<endl;
    }

    return 0;
}


