#include<bits/stdc++.h>

using namespace std;


int main()
{


    int b=3, k=19;
    set<int> s;
    set<int>:: iterator it;

    for(int i=1;i<=17;i++)
    {
        cout<<i<<" "<<b<<endl;
        s.insert((b)%k);
        b=(b*2)%k;


    }
    cout<<s.size()<<endl;

    for(it=s.begin();it!=s.end();it++)
    {

        cout<<*it<<" ";
    }
}


