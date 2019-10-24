#include<bits/stdc++.h>
#define clr(a) memset(a, 0, sizeof a)
 
 
 
using namespace std;
 
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef priority_queue<ll> mxpqi;
typedef priority_queue<ll, vector<ll> , greater<ll> > mnpqi;
 

 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
 
    int q;
    cin>>q;
 
    while(q--)
    {
 
        int n, k;
        cin>>n>>k;
 
        string x;
        cin>>x;
        string y="RGB";
 
        int ct=INT_MAX;
 
        
        vector<int> cms(n+10, 0);
        vector<int> cms1(n+10, 0);
        vector<int> cms2(n+10, 0);
 
 
        cms[0]=(x[0]!=y[0]);
        cms1[0]=(x[0]!=y[1]);
        cms2[0]=(x[0]!=y[2]);
 
        for(int i=1;i<x.size();i++)
        {
            cms[i]=cms[i-1]+(x[i]!=y[i%3]);
            cms1[i]=cms1[i-1]+(x[i]!=y[(i+1)%3]);
            cms2[i]=cms2[i-1]+(x[i]!=y[(i+2)%3]);
        }
 
 
 
        ct=min(ct, cms[k-1]);
        ct=min(ct, cms1[k-1]);
        ct=min(ct, cms2[k-1]);
 
 
        for(int i=0;i+k<x.size();i++)
        {
            ct=min(ct,  cms[i+k]-cms[i]);
            ct=min(ct,  cms1[i+k]-cms1[i]);
            ct=min(ct,  cms2[i+k]-cms2[i]);
             // cout<<ct<<endl;
        }
 
 
 
        cout<<ct<<endl;
    }
 
 
    return 0;
}