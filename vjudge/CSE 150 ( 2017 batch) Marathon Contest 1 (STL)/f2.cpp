#include<bits/stdc++.h>

using namespace std;

string isb(string s)
{
    if(s.size()%2!=0) return "NO";
     stack<char>st;
     for(int i=0;i<s.size()-1;i++)
     {
         char x=s[i];
            switch(x)
            {
            case '{':
                st.push('{');
//                cout<<st.top()<<endl;
                break;

            case '[':
                st.push('[');
//                cout<<st.top()<<endl;
                break;

            case '(':
                st.push('(');
//                cout<<st.top()<<endl;
                break;

            case ')':
                if(!st.empty()&&st.top()=='(')
                {
                    st.pop();
//                    cout<<st.top()<<endl;
                }
                else return "NO";
                break;

            case '}':
                if(!st.empty()&&st.top()=='{')
                {
                    st.pop();
//                    cout<<st.top()<<endl;
                }
                else return "NO";
                break;

            case ']':
                if(!st.empty()&&st.top()=='[')
                {
                    st.pop();
//                    cout<<st.top()<<endl;
                }
                else return "NO";
                break;
            }
    }
    return "YES";
}

int main()
{

    stack<char> st;

    char ch;
    int n;
    cin>>n;
    while(n--)
    {
//        cout<<n<<endl;
        string s;
        cin>>s;

        cout<<isb(s)<<endl;
    }

    return 0;

}



