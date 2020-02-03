#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 1100000
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    int in=0;
    while(t--)
    {
        in++;
        string x;
        cin>>x;
        int kl=0;
        int xr=0;
        int ct=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='X')
            {
                if(kl==0) xr^=lkula(ct);
                else xr^=bondo(ct);
                ct=0;
                kl=1;
            }
            else ct++;
        }
        if(kl==0) xr^=kula(ct);
        else xr^=rkula(ct);

    }

}
