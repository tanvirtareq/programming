 #include<bits/stdc++.h>

 using namespace std;

 void print(map<int, int>mp)
 {
     map<int, int>::iterator it;

     cout<<"Key\tvalue"<<endl;

     for(it=mp.begin();it!=mp.end();it++)
     {
         cout<<it->first<<"\t"<<it->second<<endl;

     }
     cout<<endl;
     cout<<endl;
 }

 int main()
 {
     map<int, int>mp;
///inserting
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(1, 30));/// if we use same key in 2 then last inserting is ignored
    mp.insert(pair<int, int>(4, 40));
    mp.insert(pair<int, int>(5, 50));
    mp.insert(pair<int, int>(6, 60));
    mp.insert(pair<int, int>(7, 70));
    mp.insert(pair<int, int>(8, 80));
    mp.insert(pair<int, int>(9, 90));

    print(mp);

///assigning one map to another
    map<int, int>mp1(mp.begin(), mp.end());

    cout<<"mp1 is"<<endl;

    print(mp1);

    /// remove upto find the key 5
    mp1.erase(mp1.begin(), mp1.find(5));
    print(mp1);

    int num=mp1.erase(7);

    cout<<num<<endl;
    print(mp1);

    cout<<"lower bound key"<<mp.lower_bound(2)->first<<endl;
    cout<<"lower bound element"<<mp.lower_bound(2)->second<<endl;
    cout<<"upper bound key"<<mp.upper_bound(2)->first<<endl;
    cout<<"upper bound element"<<mp.upper_bound(2)->second<<endl;
    print(mp);

     return 0;
 }

