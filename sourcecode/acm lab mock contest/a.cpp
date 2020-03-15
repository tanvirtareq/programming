#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(cin>>s){

    long long unsigned x=0;
    for(int i=0;i<s.size();i++)
    {
        x+=s[i]-'0';

    }

    cout<<x<<endl;
}
    return 0;
}
