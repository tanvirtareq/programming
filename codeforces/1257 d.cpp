#include<bits/stdc++.h>

#define dbg(x) cout<<#x<<"= "<<x<<endl;

using namespace std;

int mn[200010], bst[200010];

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<=n;i++) bst[i]=0;
        for(int i=1;i<=n;i++) cin>>mn[i];
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x , y;
            cin>>x>>y;
            if(y<=n)
            bst[y]=max(x, bst[y]);
        }
        int res=0;

        for(int i=n-1;i>=0;i--) bst[i]=max(bst[i], bst[i+1]);
//        for(int i=n-1;i>=0;i--) cout<<bst[i]<<endl;

        int ok=1;

        for(int i=1;i<=n;)
        {
            int mx=mn[i];

            res++;

            int j=i-1;

            while(bst[j-i+1]>=mx) j++, mx=max(mx, mn[j]);

            if(j>n) break;

            if(j==(i-1)){
                    ok=0;
            break;
            }

            i=j;
//            dbg(i);

        }

        if(!ok) res=-1;
        cout<<res<<endl;

    }

    return 0;

}
