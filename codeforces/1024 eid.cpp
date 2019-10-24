#include<bits/stdc++.h>
typedef long long unsigned llu;


using namespace std;

llu LCM(llu a,llu b)
{
    llu g=__gcd(a, b);

    return (a/g)*b;
}

int main()
{
    llu n, t;
    cin>>t;
    for(llu i=1;i<=t;i++)
    {
        llu n, lcm=1;
        cin>>n;
        while(n--)
        {
            llu x;
            cin>>x;
            lcm=LCM(lcm, x);
        }
        cout<<"Case "<<i<<": "<<lcm<<endl;

    }

    return 0;
}

