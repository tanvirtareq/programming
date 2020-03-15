#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1)

#define e 0.0000001

int main()
{
    double n, R, r, dr, ans=0;

    cin>>n>>R>>r;
    dr=R-r;

    if(2*r>R&&r<=R)
    {
        ans=1;
//        if(ans>=n) cout<<"YES"<<endl;
//        return 0;
    }
    else
    {
        ans=floor(2*pi*dr/(2*r));
//        cout<<ans<<endl;
    }
    cout<<(double)n*r/(double)(dr)<<endl;
    if(pi+e>(double)n*r/(double)(dr)) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}
