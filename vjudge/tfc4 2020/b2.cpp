#include<bits/stdc++.h>
#define mxx 100000000
#define ll long long
using namespace std;

ll totient(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main()
{

    ll t;
//    scanf("%lld" , &t);
    cin>>t;

    for(int in=1; in<=t; in++)
    {
        ll n, q;
//        scanf("%lld%lld", &n, &q);
        cin>>n>>q;
//        printf("Case %d\n", in);
        cout<<"Case "<<in<<endl;
        if(q==0)
            continue;
        vector<ll> v1, v2, v3, v4;

        ll x=totient(n);
        v1.push_back(1);
        v2.push_back(x);

        for(ll i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                x=totient(n/i);
                v1.push_back(i);
                v2.push_back(x);
                if(i*i==n) break;
                x=totient(i);

                v3.push_back(n/i);
                v4.push_back(x);
            }
        }
        ll d=v2[0];

        for(int i=1; i<v2.size(); i++)
        {
            v2[i]+=v2[i-1];
            d=v2[i];
        }

        for(int i=v3.size()-1; i>=0; i--)
        {
            d+=v4[i];
            v2.push_back(d);
            v1.push_back(v3[i]);
        }
        v2.push_back(d+1);
        v1.push_back(n);

        while(q--)
        {
//            scanf("%lld", &x);
            cin>>x;
            if(x<=0 || n==0 )
            {
//                printf("0\n");
                cout<<0<<endl;
                continue;
            }
            auto it=upper_bound(v1.begin(), v1.end(), x);

            int id=(ll)(it-v1.begin());
            if(id==v1.size())
                id--;
            else if(id<v1.size() and v1[id]>x)
                id--;
//            printf("%lld\n", v2[id]);
            cout<<v2[id]<<endl;
        }


    }

    return 0;
}

/**

2
30 3
1
2
10
0 2
1
2


1
810

*/
