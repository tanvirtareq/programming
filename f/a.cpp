#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    lld n, s=0;
    lld x;
    cin>>n;

    while(n--)
    {
        cin>>x;
        s+=x;
    }
    cout<<s<<endl;

    return 0;
}
