#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int odd=0;
        int evn=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x%2) odd=1;
            else evn=1;
        }

        if(n%2 and odd==1)
        {
            cout<<"YES"<<endl;
        }
        else if(n%2==0 and odd==1 and evn==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
