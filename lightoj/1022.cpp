#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    double r, ans;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>r;
        ans=4*r*r-2*acos(0.0)*r*r+0.000000001;
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<4*r*r-2*acos(0.0)*r*r<<endl;

    }

    return 0;
}
