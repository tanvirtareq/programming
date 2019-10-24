#include<bits/stdc++.h>




#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define pb push_back
#define mk make_pair
#define clr(a) memset(a, 0, sizeof a)
#define dbg cout<<"yes"<<endl;

using namespace std;

typedef long long ll;
typedef long long unsigned lu;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> mxpqi;
typedef priority_queue<int, vector<int> , greater<int> > mnpqi;



int  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   ll  t;
   ll  in=0;
   cin>>t;
   while(t--)
   {
      ll  n;
      cin>>n;
      vi vp, vn;
      for(ll  i=1;i<=n;i++)
      {
        ll  x;
        cin>>x;
        (x>=0)? vp.pb(x): vn.pb(-x);
      }

      sort(vp.begin(), vp.end());
      sort(vn.begin(), vn.end());
      reverse(vp.begin(), vp.end());
      reverse(vn.begin(), vn.end());
      ll  ans=0;
      ll  ad=0;

      ll ct0=0;
      for(ll  i=0;i<vp.size();i++)
      {
          if(vp[i]<=1)
          {
            for(ll  j=i;j<vp.size();j++)
            {
              if(vp[j]==0)
              {
                ct0++;
                continue;
              }
              ans+=vp[j];
            }
            break;
          }
          if(ad==0)
            ad=vp[i];
          else 
          {
            ans+=ad*vp[i];
            ad=0;
          }

      }
      ans+=ad;
      ad=0;

      for(ll  i=0;i<vn.size();i++)
      {
          if(ad==0)
            ad=vn[i];

          else 
          {
            ans+=ad*vn[i];
            ad=0;
          }

      }
      if(ct0==0)
      ans-=ad;
      cout<<ans<<endl;
      
   }


	return 0;
}