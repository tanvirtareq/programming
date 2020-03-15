#include<bits/stdc++.h>

using namespace std;

typedef long long int llu;

int main()
{
    llu t, n;

    cin>>t;
    while(t--)
    {
        cin>>n;

        cout<<"1 1";

        llu b=n-ceil((float)n/2);
        while(b--)
        {
            cout<<"0";
        }
        cout<<endl;

    }

    return 0;
}
