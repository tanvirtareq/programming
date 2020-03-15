#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define ii pair<int, int>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    while(n--)
    {
       ll x;
       cin>>x;
       ll fc=0;
       if(x<15)
       {
           cout<<"NO"<<endl;
           continue;
       }
       for(ll i=15;i<=20;i++)
       {
           if((x-i)%14==0)
           {
               fc=1;
               break;
           }
       }
       if(fc) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

    }


    return 0;
}

