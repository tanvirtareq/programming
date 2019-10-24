#include<bits/stdc++.h>

using namespace std;

unsigned long long popcount(unsigned long long n)
{
    unsigned long long c=0;
    while(n)
    {
        n=n&(n-1);
        c++;
    }
    return c;
}

int main()
{
    int t;

//    cout<<popcount(536870912)<<endl;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        unsigned long long n, b1n, ans;
        cin>>n;
        b1n=popcount(n);
        while(++n)
        {
            if(b1n==popcount(n))
            {
                ans=n;
                break;
            }

        }
        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}

/** 1
536870912
*/

