#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<char>s, t;

    char ch;

//    while(1)
//    {
//        cin>>ch;
//        printf("%d\n", ch);
//    }

    while(scanf("%c", &ch))
    {
        if(ch==10||ch=='\0'||ch=='\n') break;

        s.push_back(ch);
    }

    while(scanf("%c", &ch))
    {
        if(ch==10||ch=='\0'||ch=='\n') break;

        t.push_back(ch);
    }
    int i=1;
    int cnt=0;
    while(1)
    {
        if(i==s.size()||t.size())
        {
            break;
        }
        if(s[s.size()-i]==t[t.size()-i])
        {
            cnt=cnt+2;
            cout<<cnt<<endl;
        }
        else break;
    }

    cout<<s.size()+t.size()-cnt;

    return 0;
}

