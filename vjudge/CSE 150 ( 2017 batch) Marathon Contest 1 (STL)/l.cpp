#include<bits/stdc++.h>

using namespace std;


int main()
{
    map<queue<char>, int >mp;
    map<queue<char>, int >::iterator it;
    queue<char> q;
    queue<char> mx;
    char ch;
     int n;

     cin>>n;
     cin>>ch;
     q.push(ch);
     n--;
     while(n--)
     {
         cin>>ch;
         q.push(ch);
//         cout<<q.front()<<q.back()<<endl;
         mp[q]++;
//         cout<<mp[q];
         q.pop();

     }

     int max=0;

     for(it=mp.begin();it!=mp.end();it++)
     {
         if(max<it->second)
         {
             max=it->second;
             mx=it->first;
         }
     }
     cout<<mx.front()<<mx.back()<<endl;


    return 0;

}


