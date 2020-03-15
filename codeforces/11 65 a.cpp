#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned
#define ii pair<int, int>
#define vi vector<int>


using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin>>q;
    while(q--)
    {
        ll a[5];
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a+3);
        ll md=(a[0]+a[2])/2;
        for(ll i=0;i<=2;i++)
        {
            if(a[i]>md) a[i]--;
            else if(a[i]<md) a[i]++;
        }

        ll ans=abs(a[0]-a[1])+abs(a[0]-a[2])+abs(a[1]-a[2]);
        cout<<ans<<endl;
    }

    return 0;
}
