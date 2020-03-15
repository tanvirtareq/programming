 #include<bits/stdc++.h>

 using namespace std;

 void print(deque<int>d)
 {
     deque<int>::iterator it;

     for(it=d.begin();it!=d.end();it++)
     {
         cout<<*it<<"\t";

     }
     cout<<endl;
 }

 int main()
 {
     deque<int>d;

    d.push_back(0);
     print(d);

     d.push_back(-1);
     print(d);

     d.push_back(-2);
     print(d);

     d.push_front(1);
     print(d);

     d.pop_front();
     print(d);

     d.pop_back();
     print(d);

    d.push_back(-3);

    d.push_front(2);

    d.push_front(3);

    print(d);

    cout<<"size="<<d.size()<<endl;
    cout<<"max size="<<d.max_size()<<endl;

    cout<<"rightmost="<<d.back()<<endl;


    cout<<"leftmost="<<d.front()<<endl;

    cout<<"2nd="<<d.at(1)<<endl;


     return 0;
 }
