#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long int lld;
typedef unsigned long long ull;

using namespace std;


int main()
{
    string x;
    cin>>x;

    stack<char> st;
    int s=0;

    for(int i=0;i<x.size();i++)
    {

        if(x[i]=='[' ||
           x[i]=='{' ||
           x[i]=='<' ||
           x[i]=='(' )
            st.push(x[i]);

        else if(st.empty())
        {
            cout<<"Impossible"<<endl;
            return 0;
        }

        else if(x[i]==']')
        {

            if(st.top()!='[')
            {
                s++;
            }
            st.pop();
        }

        else if(x[i]==')')
        {
            if(st.top()!='(')
            {
                s++;
            }
            st.pop();
        }

        else if(x[i]=='>')
        {
            if(st.top()!='<')
            {
                s++;
            }
            st.pop();
        }

        else if(x[i]=='}')
        {
            if(st.top()!='{')
            {
                s++;
//                cout<<s<<" adf"<<endl;
            }
            st.pop();
        }

//        cout<<s<<endl;

    }

    if(!st.empty())
    {
//        cout<<st.top()<<endl;
        cout<<"Impossible"<<endl;
    }

    else cout<<s<<endl;

	return 0;
}

