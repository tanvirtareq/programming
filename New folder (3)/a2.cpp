#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1)
#define e 0.01

int main()
{
    int n, R, r, dr, ans=0;

    cin>>n>>R>>r;
    dr=R-r;

    if(2*r>R&&r<=R) ans=1;
    else
    {
        ans=floor((float)2*pi*dr/(2*r));
    }
    if(ans+e>n) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}
