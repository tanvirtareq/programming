#include<bits/stdc++.h>

using namespace std;

    vector<string> v;

bool issub(int i)
{
    bool f=0;
    if(v[i].size()>v[i+1].size()) return 0;
    for(short i=0;i<v[i+1].size()-v[i].size()+1;i++)
    {
        short temp=i;
        for(short j=0;j<v[i].size();j++)
        {
            if(v[i+1][temp++]!=v[i][j])
            {
                f=0;
                break;

            }
            else f=1;
        }
        if(f==1) break;
    }
    return f;
}

bool comp(string x, string y)
{
      bool f=0;
    if(x.size()>y.size()) return !f;
    for(short i=0;i<y.size()-x.size()+1;i++)
    {
        short temp=i;
        for(short j=0;j<x.size();j++)
        {
            if(y[temp++]!=x[j])
            {
                f=0;
                break;

            }
            else f=1;
        }
        if(f==1) break;
    }
    return !f;
}

int main()
{


    short n;

    cin>>n;

    while(n--)
    {
        string temp1;
        cin>>temp1;
        v.push_back(temp1);
    }

    sort(v.begin(), v.end(), comp);

    bool f=1;

    for(short i=0;i<v.size()-1;i++)
    {
        if(!isspace(i)) f=0;
    }
    if(f==1)
    {
        cout<<"YES"<<endl;
        for(short i=0;i<v.size();i++)
            cout<<v[i]<<endl;
    }
    else cout<<"NO"<<endl;


    return 0;

}
