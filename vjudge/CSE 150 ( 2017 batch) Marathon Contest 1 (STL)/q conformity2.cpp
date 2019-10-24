#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, mxs, ns, x;
    map<int, int> mp;

    int v[10010][5], st[10010];

    while(cin>>n)
    {
        mxs=0;
        mp.clear();
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>v[i][j];
                mp[v[i][j]]++;
            }

        }

        for(int i=0;i<n;i++)
        {
            int tot=0;
            for(int j=0;j<5;j++)
            {
               tot+=mp[v[i][j]];
            }
            st[i]=tot;
            if(mxs<tot) mxs=tot;
        }
        int c=0;

//        cout<<"MXS="<<mxs<<endl;
        for(int i=0;i<n;i++)
        {
          if(st[i]==mxs) c++;
        }
        cout<<c<<endl;
    }

    return 0;
}
