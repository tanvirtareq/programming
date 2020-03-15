#include<bits/stdc++.h>
#define ll long long unsigned
#define dbg(x) cout<<#x<<" = "<<x<<endl

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll m, n;
        cin>>m>>n;
        ll zero=m-n;
        ll faka=zero-1;
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }

        ll x=zero/(n+1);
        ll y=zero%(n+1);
        n++;

        ll baki=n-y;

        ll ans=m*(m+1)/2-baki*(x*(x+1)/2)-y*(x+1)*(x+2)/2;

//        ll ans=m*(m+1)/2-(x*(x+1)/2)*(n-1)-y1*(y1+1)/2-y2*(y2+1)/2;
        cout<<ans<<endl;

    }

}



