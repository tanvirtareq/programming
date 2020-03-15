#include<bits/stdc++.h>
 
 
 
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
 
        for(int i=0;i<x.size()-k+1;i++)
        {
            int m=0;
            
            for(int j=0;j<k && (i+j)<x.size();j++)
            {
                if(x[i+j]!=y[j%3])
                {
                    m++;
                }
 
            }
            // cout<<i<<" "<<m<<endl;
            ct=min(ct, m);
 
            m=0;
             for(int j=0;j<k && (i+j)<x.size();j++)
            {
                if(x[i+j]!=y[(j+1)%3])
                {
                    m++;
                }
 
            }
             // cout<<i<<" "<<m<<endl;
            ct=min(ct, m);
 
            m=0;
             for(int j=0;j<k && (i+j)<x.size();j++)
            {
                if(x[i+j]!=y[(j+2)%3])
                {
                    m++;
                }
 
            }
             // cout<<i<<" "<<m<<endl;
            ct=min(ct, m);
            // cout<<ct<<endl;
 
 
        }
 
        cout<<ct<<endl;
    }
 
 
	return 0;
}