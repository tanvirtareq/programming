#include<bits/stdc++.h>

using namespace std;

int main()
{
////
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    vector<string>st;

    char ch;

    map<string, int>mp;

    vector<string>v;

    int i=0;

    while(scanf("%c", &ch)!=EOF)
    {
        if(isalpha(ch))
        {

            st[i]=tolower(ch);
            i++;

//            continue;

        }

        else if(i!=0)
        {
            st[i]='\0';


            cout<<"str size="<<st.size()<<"i="<<i;

            i=0;

            if(mp[st]==0)
            {
                mp[st]=1;
                v.push_back(st);

            }
        }
    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;

    }


}

