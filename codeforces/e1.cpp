#include<bits/stdc++.h>
#define ll long long

using namespace std;

int c[3000];

vector<int> ad[3000];

int dfs(int rt, int p, int cl)
{
    c[rt]=cl;

    for(int i=0;i<ad[rt].size();i++)
    {
        int nw=ad[rt][i];
        if(nw==p) continue;

        if(c[nw]!=-1)
        {
            if(c[nw]==!cl) continue;
            cout<<"NO"<<endl;
            exit(0);
        }
        dfs(nw, rt, !cl);
    }

}

int main()
{
   int n;
   cin>>n;
   string x;

   cin>>x;

   memset(c, -1, sizeof c);

   for(int i=0;i<x.size();i++)
   {
       for(int j=i+1;j<x.size();j++)
       {
           if(x[i]>x[j])
           {
               ad[i+1].push_back(j+1);
               ad[j+1].push_back(i+1);
           }
       }
   }

   for(int i=1;i<=n;i++)
   {
       if(c[i]==-1)
       {
           dfs(i, i, 0);
       }
   }

   cout<<"YES"<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<c[i];
   }

    return 0;
}



