#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned lld;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(n==1) cout<<"3"<<endl;
        else
        {
            cout<<"1";
            for(int i=2;i<n;i++)
                cout<<"0";
            cout<<"2"<<endl;
        }
    }

    return 0;
}





