#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<"="<<a<<endl;
#define ii pair<int, int>
#define vi vector<int>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll a, b;
        cin>>a>>b;
        ll d=abs(a-b);
        ll n= sqrt(2*d)-10;
        n=max(0LL, n);
        while(1)
        {
            if(n*(n+1) >= 2*d and (n*(n+1)-2*d)%4==0) break;
            n++;
        }
        cout<<n<<endl;

    }



    return 0;
}
/**
1 1

1 2

*/

