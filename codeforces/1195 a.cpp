#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;

int main()
{
//   #ifndef ONILINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;
    cin>>n>>k;

    int v[k+10]={0};

    fr(i, n)
    {
        int x;
        cin>>x;
        v[x]++;

    }

    int ct=0;

    fr(i, k)
    {
        ct+=v[i]/2;
        // cout<<ct<<endl;
        v[i]%=2;
    }
    ct*=2;
    // cout<<ct<<endl;

    int f=0;
    fr(i, k)
    {
        f+=v[i];
    }

    ct+=ceil((double)f/2.0);

    cout<<ct<<endl;
  
    return 0;
}

