
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,cn=0;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s[0]=='n'&&s[s.size()-1]=='d') cn++;

    }

    cout<<cn<<endl;
}
