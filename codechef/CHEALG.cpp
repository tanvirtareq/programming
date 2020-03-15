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
       string x;
       cin>>x;
       char ch=x[0];
       int ct=1;
       int ct2=0;
       for(int i=1;i<x.size();i++)
       {
           if(ch==x[i]) ct++;
           else
           {
              ct2+=1+log10(ct)+1;
              ct=1;
              ch=x[i];
           }
       }
       ct2+=1+log10(ct)+1;
       if(ct2<x.size()) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}






