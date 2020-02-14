#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, a, b, k;
    cin>>n>>a>>b>>k;
    ll md=a+b;

    vector<ll> v;

    ll ans =0;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;

        ll y=x%md;
        if(y>0 and y<=a) ans++;
        else
        {
            if(y==0) y=md;
            y=y-a;
            ll fc=y/a;
            if(y%a) fc++;

            v.push_back(fc);

//            cout<<fc<<endl;
//            cout<<"fc "<<fc<<endl;
        }

    }

//    cout<<ans<<endl;

    sort(v.begin(), v.end());

    ll fc=0;

    for(int i=0;i<v.size();i++)
    {
//        cout<<v[i]<<endl;
        fc+=v[i];
        if(fc>k) break;
        ans++;
//        cout<<ans<<endl;
    }

    cout<<ans<<endl;



    return 0;
}



