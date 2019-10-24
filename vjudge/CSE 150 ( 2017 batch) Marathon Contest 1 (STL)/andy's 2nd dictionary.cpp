#include<bits/stdc++.h>

using namespace std;

map<string, int>s;
map<string, int>::iterator it;
vector<string> v;

string stte;
int x;

string inp(char ar[])
{
    string st;
    int l=strlen(ar);

    for(int i=0;i<l;i++)
    {
        if(isalpha(ar[i])||ar[i]=='-')
        {
            ar[i]=tolower(ar[i]);
            st.push_back(ar[i]);
        }
        else
        {
            if(x==1)
            {

                stte+=st;
                if(s[stte]!=1&&stte!="-"&&stte.size()!=0) v.push_back(stte);
    //            if(s[stte]!=1) cout<<"("<<stte<<")"<<endl;
                s[stte]=1;
                stte.clear();
                x=0;
                st.clear();

            }
            else
            {
                if(s[st]!=1&&st!="-"&&st.size()!=0) v.push_back(st);
    //            if(s[st]!=1) cout<<"("<<st<<")"<<endl;
                s[st]=1;
                st.clear();
            }
        }

    }

    return st;
}

int main()
{

    string st;
    char ar[1000];

    while(scanf("%s", ar)!=EOF)
    {
        st=inp(ar);
        if(st[st.size()-1]=='-')
        {
            st.erase(st.end()-1);
            stte+=st;
            st.clear();
            x=1;
        }
        else if(x==1)
        {
            stte+=st;
            if(s[stte]!=1&&stte!="-"&&stte.size()!=0) v.push_back(stte);
//            if(s[stte]!=1) cout<<"("<<stte<<")"<<endl;
            s[stte]=1;
            stte.clear();
            x=0;
        }
        else
        {
            if(s[st]!=1&&st!="-"&&st.size()!=0) v.push_back(st);
//            if(s[st]!=1) cout<<"("<<st<<")"<<endl;
            s[st]=1;
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    return 0;
}
