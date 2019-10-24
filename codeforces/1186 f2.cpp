#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;
 vector<int> v[1000010], v1[1000010];
 int vis[1000100];

 vector<int> eulerCircuit(int rt)
 {

     vector<int> path, temp;
     if(v1[rt].size()==0) return path;

     int ch=v1[rt].back();
     int prev=rt;
     temp.pb(rt);
    clrar(vis);

     while(ch!=rt)
     {
         if(v1[ch].size()>2) vis[ch]=1;
         else vis[ch]=0;

         temp.pb(ch);
         v1[prev].pop_back();
         auto it=find(v1[ch].begin(), v1[ch].end(), prev);

         v1[ch].erase(it);

         prev=ch;
         ch=v1[ch].back();
     }
      temp.pb(ch);
         v1[prev].pop_back();
         auto it=find(v1[ch].begin(), v1[ch].end(), prev);

         v1[ch].erase(it);

     for(int i=0;i<temp.size();i++)
     {
         ch=temp[i];
         if(vis[ch]==0 || ch==rt)
         {
             path.pb(ch);

         }
         else {
            vector<int> ans=eulerCircuit(ch);
            for(auto j:ans)
            {
                path.pb(j);
            }

         }

     }
     return path;

 }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n, m;
   cin>>n>>m;

   f(m)
   {
       int x, y;
       cin>>x>>y;
       v[x].pb(y);
       v[y].pb(x);
       v1[x].pb(y);
       v1[y].pb(x);

   }

   fr(i, n)
   {

        if(v1[i].size()%2==1)
        {
            v1[i].pb(0);
            v1[0].pb(i);
            v[i].pb(0);
            v[0].pb(i);

        }
   }

   vector<int> path=eulerCircuit(0);

   int  i;
   for(i=2;i<path.size();i+=2)
   {
       if(path[i]==0 || path[i-1]==0 || path[i+1]!=0 && path[i-2]!=0)
       {
           int ch1=path[i];
           int ch2=path[i-1];
           v[ch1].erase(find(v[ch1].begin(), v[ch1].end(), ch2));
           v[ch2].erase(find(v[ch2].begin(), v[ch2].end(), ch1));
       }
       else if(path[i-2]==0)
       {
           int ch1=path[i-2];
           int ch2=path[i-1];
           v[ch1].erase(find(v[ch1].begin(), v[ch1].end(), ch2));
           v[ch2].erase(find(v[ch2].begin(), v[ch2].end(), ch1));
       }
       else if(path[i+1]==0)
       {
           int ch1=path[i];
           int ch2=path[i+1];
           v[ch1].erase(find(v[ch1].begin(), v[ch1].end(), ch2));
           v[ch2].erase(find(v[ch2].begin(), v[ch2].end(), ch1));

       }

   }



    int k=0;




    return 0;
}
