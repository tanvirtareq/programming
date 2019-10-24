
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int u=0, l=0;

    string s;

    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(islower(s[i])) l++;

        else u++;

    }

    if(u>l)
    {
    for(int i=0;i<s.size();i++)
    {
        s[i]=toupper(s[i]);

    }

    }

    else for(int i=0;i<s.size();i++)
    {
        s[i]=tolower(s[i]);

    }

    cout<<s;

    return 0;
}

