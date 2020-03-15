#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n;

    string s;
    cin>>n>>s;

    ll x=0;

    for(int i=1;i<s.size();i+=2)
    {
        if(s[i]==s[i-1])
        {
            x++;
            if(s[i]=='a') s[i-1]='b';
            else s[i-1]='a';
        }
    }

    cout<<x<<endl<<s<<endl;


    
    return 0;
}
