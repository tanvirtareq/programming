#include<bits/stdc++.h>

using namespace std;

map<string, int>mp;

string st;

void inputf()
{
    char ch;
    while(scanf("%c", &ch)!=EOF)
    {
        if(isalpha(ch))
        {
            char c=tolower(ch);
            st.push_back(c);
        }
        else if(!st.empty())
        {
            mp[st]=1;
            st.clear();
        }
    }

    return;
}

void outputf()
{
    map<string, int>::iterator i;

    for(i=mp.begin();i!=mp.end();i++)
    {
        cout<<i->first<<endl;
    }

    return;
}

int main()
{

    inputf();

    outputf();


}

