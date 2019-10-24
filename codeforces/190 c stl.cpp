#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<char> st1;
    stack<pair<int, int> >st2;
    pair<int, int> pr;
    string s, ans;
    char c;

    int n;
    cin>>n;

    while(cin>>s)
    {
        if(s=="pair")
        {
            st1.push('>');
            st2.push(make_pair(1, 1));
            ans+=s;
            ans.push_back('<');
            cout<<ans<<endl;
        }

        else
        {
           if(st2.top().first!=0)
           {
               st2.pop();
               st2.push(make_pair(0, 1));
               ans+=s;
               ans.push_back(',');
                 cout<<ans<<endl;
           }
           else
           {
               st2.top().second=0;
               ans+=s;
               ans.push_back(st1.top());
                 cout<<ans<<endl;
               st1.pop();

                while(1)
                {
                    pr=st2.top();
                    if(st2.top().second!=0) break;
                    c=st1.top();
                    st1.pop();
                    ans.push_back('>');
                      cout<<ans<<endl;
                    st2.pop();
                }
                ans.push_back(',');
                  cout<<ans<<endl;

            }

        }


    }
    cout<<ans<<endl;
    return 0;
}
