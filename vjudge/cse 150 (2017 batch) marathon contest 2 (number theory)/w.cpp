#include<bits/stdc++.h>
#define sz 100000000000000000000
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, b, ans=0;
        cin>>n>>b;
        while(b--)
        {
            int x, md=1;
            cin>>x;
            while(x--)
            {
                int tm;
                cin>>tm;
                md=(md*tm)%n;
            }
            ans=(ans+md)%n;
        }
        cout<<ans<<endl;
    }
    return 0;
}


