#include<bits/stdc++.h>

using namespace std;

typedef long long unsigned lld;

struct a{
int score ;
string name;

};

bool comp(a p, a q)
{
    if(p.score==q.score) return p.name<q.name;
     return p.score>q.score;

}


int main()
{
    int t;
    cin>>t;
    vector<a> v;
    while(t--)
    {
      string st;
      cin>>st;
      int x;
      cin>>x;
      int sc=0;
      while(x--)
      {
          int t;
          cin>>t;
          sc+=t;
      }
      a tmp;
      tmp.name=st;
      tmp.score=sc;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].name<<endl;
    }


    return 0;
}
