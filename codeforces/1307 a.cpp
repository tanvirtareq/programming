#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin>>t;

    for(int in=1;in<=t;in++)
    {
        int n,m;
        cin>>n>>m;
        int s=0;
        cin>>s;
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            int fc=min(x, m/i);
            s+=fc;
            m-=fc*i;
        }
        cout<<s<<endl;
    }


    return 0;
}

