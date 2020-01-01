#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl;
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);

    for(int in=1;in<=q;in++)
    {
        ll h, m;
        cin>>h>>m;
        ll x=h%m;
        ll k=m/2;
        if(x>k)
        {
            cout<<h-(x-k)<<endl;
        }
        else cout<<h<<endl;

    }
    return 0;
}









