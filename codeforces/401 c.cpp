#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll m, n;
    cin>>n>>m;
    if(2*n+2<m || m+1<n)
    {
        cout<<-1<<endl;
        return 0;
    }
    string s;
    if(m+1==n)
    {
        s.push_back('0');
        for(int i=1;i<=m;i++)
        {
            s.push_back('1');
            s.push_back('0');
        }
        cout<<s<<endl;
        return 0;
    }
    while(m-1>n and m>0 and n>0)
    {
        s.push_back('1');
        m--;
        if(m<=0) break;
        s.push_back('1');
        m--;
        s.push_back('0');
        n--;
    }
    if(m-1>=n)
    {
        s.push_back('1');
        m--;
    }
    while(m+n>0)
    {
        if(m>0) s.push_back('1');
        m--;
        if(n>0) s.push_back('0');
        n--;
    }
    cout<<s<<endl;
    return 0 ;
}

