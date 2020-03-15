#include<bits/stdc++.h>

using namespace std;

string isb(string s)
{
    //if(s.size()%2!=0) return "NO";
     stack<char>st;
     for(int i=0;i<=s.size();i++)
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

                default :continue;
            }
    }
    if(st.empty())
    return "YES";
    else return "NO";
}

int main()
{

    stack<char> st;

    char ch;
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
    {
//        cout<<n<<endl;
        string s;
        getline(cin, s);

        cout<<isb(s)<<endl;
    }

    return 0;

}
