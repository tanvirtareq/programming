#include<bits/stdc++.h>

using namespace std;


bool issub(string x, string y)
{
    bool f=0;
    if(x.size()>y.size()) return 0;
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
    return f;
}

bool comp(string x, string y)
{
    return x.size()<y.size();
}

int main()
{

    vector<string> v;
    short n;

    cin>>n;

    while(n--)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), comp);
//    for(short i=0;i<v.size();i++)
//            cout<<v[i]<<endl;

    bool f=1;

    for(short i=0;i<v.size()-1;i++)
    {
        if(!issub(v[i],v[i+1])) f=0;
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
