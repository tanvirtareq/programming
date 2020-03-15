#include<bits/stdc++.h>

using namespace std;

int main()
{
////
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string st;

    char ch;

    map<string, int>mp;

    vector<string>v;

    while(cin>>ch)
    {

        for(int i=0;i<st.size();i++)
        {
            if(!isalpha(st[i])&&st[i]!='-')
            {
                st.erase(st.begin()+i);
                i--;
            }

            else if(isalpha(st[i]))
            {
                st[i]=tolower(st[i]);

            }


        }

        if(mp[st]==0)
        {
            mp[st]=1;


            v.push_back(st);


        }


    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;

    }


}
