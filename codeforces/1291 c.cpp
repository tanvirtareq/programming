#include<bits/stdc++.h>



#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define MX 400000

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;

ll ar[MX], tree[4*MX];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
       ll n, m, k;
       cin>>n>>m>>k;
       for(ll i=1;i<=n;i++)
       {
           ll x;
           cin>>x;
           ar[i]=x;
       }

       ll x=min(k, m);
        ll ans=0;
       if(x!=k)
       {
           ll mx=0;
           for(ll i=1;i<=x;i++)
           {
               mx=max(mx, ar[i]);
           }
           reverse(ar+1, ar+n+1);
           for(ll i=1;i<=x;i++)
           {
               mx=max(mx, ar[i]);
//               dbg(mx);
           }
           cout<<mx<<endl;
       }

       else
       {
//           int drkrk=n-k;
//           int drkrm=n-m+1;
//           cout<<drkrk<<" "<<drkrm<<endl;
            ll isuru=1, ises=n-k;
            ll drkr=n-m;
           for(;ises<=n;isuru++, ises++)
           {
               ll jsuru=isuru, jses=jsuru+drkr;
               ll flt=INT_MAX;
               ll f=0;
//               dbg(isuru);
//               dbg(ises);
               for(;jses<=ises;jsuru++, jses++)
               {
                   flt=min(flt, max(ar[jsuru], ar[jses]));
                   f=1;
//                   dbg(jsuru);
//                   dbg(jses);
//                   dbg(flt);

               }
               if(f) ans=max(flt, ans);

           }

           cout<<ans<<endl;
       }

//       else
//       {
////           ll bakim=m-k-1;
//           ll drkrk=n-k;
//           for(ll i=0;i<=k;i++)
//           {
//               ll flt=ll_MAX;
//               ll sesk=i+drkrk;
//
//               for(ll j=0;j<=m-1;j++)
//               {
//                   ll drkr=n-m+1;
//                   ll suru=i+j+1;
//                   ll ses=i+drkr;
//                   flt=min(flt, max(ar[suru], ar[ses]));
//
//               }
//               ans =max(ans, flt);
////               ll suru=i+1;
////               ll ses=i+drkr;
////               cout<<i<<" "<<suru<<" "<<ses<<endl;
////               ll p=query(1, 1, n, suru, suru+bakim-1);
////               ll q=query(1, 1, n, ses-bakim+1 ,ses);
////               cout<<p<<" "<<q<<endl;
////               ans=max(ans, max(p, q));
////               cout<<i<<" "<<ans<<endl;
//           }
//           cout<<ans<<endl;
//
//       }


    }

	return 0;
}



