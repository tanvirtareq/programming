#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin>>t;

    for(int in=1;in<=t;in++)
    {
        ll n, m;
        cin>>n>>m;
        ll ar[m+10];
        for(int i=0;i<m;i++) cin>>ar[i];
        ll mx=(1<<m)-1;
        ll ans=0;
        for(int s=1;s<=mx;s++)
        {
            ll ct=0;
            ll fc=1;
            for(int i=0;i<m;i++)
            {
                if(s&(1<<i))
                {
                    ct++;
                    ll g=__gcd(fc, ar[i]);
                    fc=fc*ar[i]/g;
                }
            }
            if(ct%2) ans+=n/fc;
            else ans-=n/fc;
        }

        cout<<"Case "<<in<<": "<<n-ans<<endl;
    }


    return 0;
}
