#include<bits/stdc++.h>

using namespace std;

int main()
{
    int sx, sy, sz, x,y,z, t;
    cin>>t;
    sx=sy=sz=0;
    while(t--)
    {
        cin>>x>>y>>z;
        sx=sx+x;
        sy=sy+y;
        sz=sz+z;
    }

        if(sx==0&&sy==0&&sz==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    return 0;
}
