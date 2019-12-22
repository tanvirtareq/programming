#include<bits/stdc++.h>
#define ll long long
#define Mx 3000000
ll ar[Mx], bad[Mx], nabad[Mx];
using namespace std;
int  main()
{

    ll n;
     ll mx=0;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>ar[i];
    ar[n+1]=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
       if(ar[i]>ar[i-1])
       {
           nabad[i]=nabad[i-1]+1;
           bad[i]=bad[i-1]+1;

           if(i>=2 and ar[i]>ar[i-2] and nabad[i-2]+1>bad[i])
           {
               bad[i]=nabad[i-2]+1;
           }
       }
       else if(i>=2 and ar[i]>ar[i-2])
       {
           nabad[i]=1;
           bad[i]=nabad[i-2]+1;
       }
       else
       {
           bad[i]=1;
           nabad[i]=1;
       }

       mx=max(mx, max(bad[i], nabad[i]));
    }


    for(ll i=1;i<=n;i++) mx=max(mx, bad[i]);
//    for(ll i=1;i<=n;i++) cout<<bad[i]<<" ";
//    cout<<endl;
//    for(ll i=1;i<=n;i++) cout<<nabad[i]<<" ";
//    cout<<endl;
    cout<<mx<<endl;

    return 0;
}

/**
5
 1 2 3 4 5

5
5 4 3 2 1

5
1 1 1 1 1

5
1 2 2 3 4

5
6 1 2 3 1


*/

