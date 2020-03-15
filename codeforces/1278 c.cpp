#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<"="<<a<<endl;
#define ii pair<int, int>
#define vi vector<int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n+10], br[n+10];
        memset(ar, 0, sizeof ar);
        memset(br, 0, sizeof br);
        for(int i=n;i>0;i--)
        {
            int x;
            cin>>x;
            if(x==2) x=-1;
            ar[i]=x;
//            dbg(ar[i]);
        }
        for(int i=1;i<=n;i++) ar[i]=ar[i-1]+ar[i];

        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x==2) x=-1;
            br[i]=br[i-1]+x;
        }
//        reverse(br+1, br+n+1);

        map<int, int> mp1, mp2;
        for(int i=n;i>0;i--)
        {
            mp1[ar[i]]=i;
            mp2[br[i]]=i;
        }


        int fc=ar[n]+br[n];
        if(fc==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(ar[1]==fc or br[1]==fc)
        {
            cout<<1<<endl;
            continue;
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(ar[i]==fc)
            {
                ans=min(ans, i);
            }
            else if(mp2[fc-ar[i]]!=0)
            {
                ans=min(ans, i+mp2[fc-ar[i]]);
            }
//            dbg(ar[i]);
//            cout<<ans<<" "<<mp2[i]<<endl;

        }

        for(int i=1;i<=n;i++)
        {
            if(br[i]==fc) ans=min(ans, i);
            else if(mp1[fc-br[i]]!=0)
            {
                ans=min(ans, i+mp1[fc-br[i]]);
            }
        }

        cout<<ans<<endl;


    }



    return 0;
}
/**
1 1

1 2

*/


