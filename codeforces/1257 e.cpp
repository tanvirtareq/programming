#include<bits/stdc++.h>
#define sz 200100
using namespace std;

int ar[sz], v[sz];
int dpt[sz][5];
int n;

int dp(int state, int lst)
{
    if(state>n) return 0;
    int mn=INT_MAX;

    if(dpt[state][lst]!=-1) return dpt[state][lst];

    for(int i=lst;i<=3;i++)
    {
        if(v[state]==i) mn=min( mn,dp(state+1, i));
        else
            mn=min( mn,1+dp(state+1, i));
    }

    return dpt[state][lst]=mn;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k1, k2, k3, x;

    cin>>k1>>k2>>k3;
     n=k1+k2+k3;

     memset(dpt, -1, sizeof dpt);

    while(k1--)
    {
        cin>>x;
        ar[x]=1;
    }

    while(k2--)
    {
        cin>>x;
        ar[x]=2;
    }

    while(k3--)
    {
        cin>>x;
        ar[x]=3;
    }



    for(int i=1;i<=n;i++)
    {
        v[i]=ar[i];
//        cout<<v[i]<<endl;
    }

    cout<<dp(1, 0)<<endl;

    return 0;
}
