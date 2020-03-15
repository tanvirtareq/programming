#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll k=0, f=0, a, b, c;
       for(int i=1;i<=n;i++)
       {
           ll x;
           cin>>x;
           k+=x;
           f^=x;
       }
       ll tmp=max(2*f, 2*k)*4;
       if(k%2==1) tmp--;
        f^=tmp;
       k=k+tmp;
       a=tmp;
       ll z=2*f-k;
       cout<<3<<endl;
       cout<<a<<" "<<z/2<<" "<<z/2<<endl;


    }
    return 0;
}
