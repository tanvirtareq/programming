#include<bits/stdc++.h>

using namespace std;
typedef long long unsigned lu;

int main()
{
    lu a, n, b, k;

    lu t;

    cin>>t;

    while(t--)
    {
        cin>>n>>a>>b>>k;

        if(n/a+n/b-2*((n/a)/(b/__gcd(a, b)))>=k ) cout<<"Win"<<endl;

        else cout<<"Lose"<<endl;

    }

    return 0;
}
