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
       ll n;
       cin>>n;
       ll mn[n+10], ar[n+10];
       ar[0]=INT_MAX;
       mn[0]=0;
       for(int i=1;i<=n;i++)
       {
            cin>>ar[i];
            if(ar[mn[i-1]]<=ar[i])
            {
                mn[i]=mn[i-1];
            }
            else mn[i]=i;

//            cout<<mn[i]<<endl;
       }
       ll tk=0;
       ll ct=0;
       ll mnm=ar[mn[n]];
       tk=mnm;
       ct+=tk*n;
       ll j=mn[n]-1;
       while(j>0)
       {
           mnm=ar[mn[j]]-tk;
           if(mnm<=0)
           {
               j=mn[j]-1;
               continue;
           }
           tk+=mnm;
           ct+=mnm*j;
           j=mn[j]-1;

       }
       cout<<ct<<endl;
    }
    return 0;
}
/**

1
3
2 1 3

*/







