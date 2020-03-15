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
        ll a, m;
        cin>>a>>m;
        vector<ll> v;
        for(ll i=1;i*i<=m;i++)
        {
            if(m%i==0)
            {
                ll d=i;
                ll x=m/d-1;
                if(x>0 and x%a==0)
                    v.push_back(x*d/a);

                d=m/i;
                x=m/d-1;
                if(x>0 and x%a==0) v.push_back(x*d/a);
            }
        }
        sort(v.begin(), v.end());
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;

    }
    return 0;
}







