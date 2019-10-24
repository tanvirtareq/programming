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
    return "YES";
}

int main()
{
    string a, b, c;

    getline(cin, a);
    getline(cin, b);
    cout<<b<<endl;
    printf("\n%d\n", a[a.size()-1]);

    return 0;

}

