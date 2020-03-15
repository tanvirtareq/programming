#include<bits/stdc++.h>

using namespace std;

map<string, int>mp;

string st, st1;

void inputf()
{
    int a=0;
    char ch, p;
    while(scanf("%c", &ch)!=EOF)
    {
        if(p=='-'&&ch==10)
        {
            p=ch;
            st.pop_back();
            st1.clear();
            a=1;
            continue;
        }
        if(isalpha(ch)||ch=='-')
        {
            if(ch=='-'&&a!=1)
            {
                st1=st;
            }



            char c=tolower(ch);
            st.push_back(c);

            if(!st1.empty()&&ch!='-')
            {
                st1.push_back(c);
            }
            p=ch;
        }
        if(ch!=32&&ch!='.'&&ch!=','&&ch!=10)
        {
            st1.clear();
            if(!st.empty())
            {


             mp[st]=1;
            st.clear();
            a=0;

            }
        }

        else if(!st.empty())
        {
            mp[st]=1;
            st.clear();
            a=0;

            if(!st1.empty())
            {
                mp[st1]=1;
                st1.clear();
            }
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


