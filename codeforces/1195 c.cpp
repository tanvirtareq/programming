#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;

typedef long long ll;

ll ar0[100010], ar1[100010];
ll tab[4][100010];

 ll n;

ll dp(ll a,  ll indx)
{

    // cout<<indx<<" "<<ht<<endl;
    if(indx>n) return 0;

    if(tab[a][indx]!=-1) return max(-1LL, tab[a][indx]);

    ll x=0;
    (a)? x=ar1[indx]: x=ar0[indx];

    ll p=dp(!a, indx+1)+x;

    ll q=dp(a ,indx+1);



    tab[a][indx]=max(p, q);

    // cout<<tab[a][indx]<<endl;

    // cout<<"y"<<endl;
    return tab[a][indx];

    // return max(p, q);

}

int main()
{
//   #ifndef ONILINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
    cin>>n;

    clrar(ar0);
    clrar(ar1);
    memset(tab, -1, sizeof tab);

    fr(i, n)
    {
      cin>>ar0[i];
    }

    fr(i, n)
    {
      cin>>ar1[i];
    }

    ll ct=0;

    // ct=max(ct, dp(1, ar0[1], 2));

    // ct=max(ct, dp(0, ar1[1], 2));

    ct=max(ct, dp(1, 1));

    ct=max(ct, dp(0,  1));

    cout<<ct<<endl;

    return 0;
}

