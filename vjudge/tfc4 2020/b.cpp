#include<bits/stdc++.h>
#define mxx 100000000
#define ll long long
using namespace std;

ll totient(ll n)
{
    ll t=n;
    ll ret=n;

    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
             ret=ret-ret/i;
            while(n%i==0)
            {

                n/=i;
            }
        }
    }
    return ret;
}

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

   ll t;
//   cin>>t;
    scanf("%lld" , &t);

   for(int in=1;in<=t;in++)
   {
       ll n, q;
//       cin>>n>>q;
        scanf("%lld%lld", &n, &q);
        printf("Case %d\n", in);
        if(q==0) continue;
       vector<ll> v1, v2, v3, v4;

       ll x=totient(n);
       v1.push_back(1);
       v2.push_back(x);

       for(ll i=2;i*i<=n;i++)
       {
           if(n%i==0)
           {
               x=phi(n/i);
               v1.push_back(i);
               v2.push_back(x);
               x=phi(i);

               v3.push_back(n/i);
               v4.push_back(x);
           }
       }
       ll d;

       for(int i=1;i<v2.size();i++)
       {
           v2[i]+=v2[i-1];
           d=v2[i];
       }

       for(int i=v3.size()-1;i>=0;i--)
       {
           d+=v4[i];
           v2.push_back(d);
           v1.push_back(v3[i]);
       }

//       cout<<"Case "<<in<<endl;

       while(q--)
       {
//           cin>>x;
            scanf("%lld", &x);
           if(x<=0)
           {
//               cout<<0<<endl;
                printf("0\n");
               continue;
           }
           auto it=upper_bound(v1.begin(), v1.end(), x);

           int id=(ll)(it-v1.begin());
           id--;
//           cout<<v2[id]<<endl;
            printf("%lld\n", v2[id]);
       }


   }

    return 0;
}





