#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned lld;


int main()
{
    lld n, m, k, ans, f=1;

    cin>>n>>k;
    lld mask=(f<<k)-1;

    ans=n|mask;
    while(ans<n)
    {
        mask=mask<<1;
        ans=n|mask;
    }

    cout<<ans<<endl;

    return 0;
}
/**

364269800189924
33
*/


