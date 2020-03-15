#include<bits/stdc++.h>
#define m 10000007

typedef unsigned long long ull;
typedef long long int lld;

using namespace std;



int main() {

    map<char, int> mp;

mp['a']=1;
mp['e']=1;
mp['i']=1;
mp['o']=1;
mp['u']=1;

   string s, t;
   cin>>s>>t;

   string x, y;

//   if(mp[s[0]]==1)

    if(s.size()!=t.size())
    {
        cout<<"No"<<endl;

        return 0;

    }

   for(int i=0;i<s.size();i++)
   {
       if(mp[s[i]]!=mp[t[i]])
       {
          cout<<"No"<<endl;

          return 0;

       }

   }

   cout<<"Yes"<<endl;


    return 0;
}


