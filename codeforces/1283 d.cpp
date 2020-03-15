#include<bits/stdc++.h>
#define ll long long
#define dbg(a) cout<<#a<<"="<<a<<endl;
using namespace std;

ll adj[210000], in[210000], ot[210000], ar[210000], br[210000];
int vis[210000];
vector<ll> v[210000], asole;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m, n;
    cin>>m>>n;
    unordered_map<int, int> mp;

    for(int i=1;i<=m;i++)
    {
        cin>>ar[i];
        mp[ar[i]]=1;
    }

    int j=1;
    int k=1;

    ll ct=0;

    for(int i=1;i<=n;i++)
    {
        if(mp[ar[j]-k]==0)
        {
            mp[ar[j]-k]=1;
            br[i]=ar[j]-k;
            ct+=k;
        }
        else if(mp[ar[j]+k]==0)
        {
            mp[ar[j]+k]=1;
            br[i]=ar[j]+k;
            ct+=k;
        }
        else
        {
            j++;
            if(j>m)
            {
                j=1;
                k++;
            }
            i--;
        }
    }
    cout<<ct<<endl;
    for(int i=1;i<=n;i++) cout<<br[i]<<" ";
    cout<<endl;

    return 0;
}












