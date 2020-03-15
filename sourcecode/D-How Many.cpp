#include<bits/stdc++.h>

using namespace std;

vector<int> v[110000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;

    int mx[n+10];
    int mn[n+10];
    for(int i=1;i<=n;i++)
    {
        mx[i]=0;
        mn[i]=INT_MAX;
    }

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x<0 or x>n)
        {
            cout<<"f"<<endl;
            return 0;
        }
        mx[x]=max(mx[x], i);
        mn[x]=min(mn[x], i);
    }

    for(int i=0;i<q;i++)
    {
        int a,b,x;
        cin>>a>>b>>x;
        if(x<0 or x>n)
        {
            cout<<0<<endl;
            continue;
        }
        int l=mn[x];
        int r=mx[x];
        int ans=min(r, b)-max(l, a)+1;
        ans=max(0, ans);
        cout<<ans<<endl;
    }

}













