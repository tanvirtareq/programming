#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<char> s, t;

    char ch;

     while(scanf("%c", &ch))
    {
        if(ch==10||ch=='\0'||ch=='\n') break;

        s.push(ch);
    }

    while(scanf("%c", &ch))
    {
        if(ch==10||ch=='\0'||ch=='\n') break;

        t.push(ch);
    }
    int l=s.size()+t.size();

    int cnt=0;
    while(1)
    {
        if(s.size()&&t.size())
        {
            char a, b;
            a=s.top();
            b=t.top();
            s.pop();
            t.pop();

            if(a==b) cnt+=2;
            else break;
        }
        else break;
    }
    cout<<l-cnt;


    return 0;
}
