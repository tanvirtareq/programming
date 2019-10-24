#include<bits/stdc++.h>

using namespace std;

long long unsigned m=1000000007, s=9223372036854775808;



int main()
{
    long long unsigned a, b, ans;

    cin>>a>>b;

    ans=(((a%m)*(b%m))%m+s%m)%m;
    cout<<ans<<endl;

    return 0;
}
