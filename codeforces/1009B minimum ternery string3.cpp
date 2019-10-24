#include<bits/stdc++.h>

using namespace std;

void print(vector<char> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    return;

}

int main()
{
    int c2=0, c0=1;

    char ch;

    vector<char>v;

    while(cin>>ch)
    {
        if(ch=='0')
            c0=1;
        if(ch=='2')
            c2=1;

        if(c0==1&&c2==1)
        {
            sort(v.begin(), v.end());
            print(v);
            v.clear();
            c0=0;
            c2=0;


        }
        if(ch=='0')
            c0=1;
        if(ch=='2')
            c2=1;

        v.push_back(ch);
    }
    sort(v.begin(), v.end());
    print(v);

    return 0;
}
