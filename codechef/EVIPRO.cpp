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
       ll ct=0;
       for(int i=0;i<x.size()-1;i++)
       {
            int a=i;
            int b=i+1;
            ll rmr=x.size()-1-b;
            ll rml=a;
//            dbg(rmr);
//            dbg(rml);
            if(x[a]==x[b])
            {
//                ct+=rmr*rmr;
//                ct+=rml*rml;
                ct+=(rml-1)*rml/2+rml;
                ct+=(rmr-1)*rmr/2+rmr;
                ct+=(rmr+1)*(rml+1);
//                ct++;
            }
            else
            {
                rmr++;
                rml++;
                ct+=rmr;
                ct+=rml;
            }
       }
       cout<<ct<<endl;
    }
    return 0;
}





