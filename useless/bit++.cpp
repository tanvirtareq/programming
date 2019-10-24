
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x=0, t;

    string s;

    cin>>t;

    while(t--)
    {
        cin>>s;

        if(s=="X++"||s=="++X") x++;
        else x--;


    }

    cout<<x<<endl;


    return 0;
}
