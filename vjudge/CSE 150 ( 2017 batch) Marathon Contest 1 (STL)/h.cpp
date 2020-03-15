#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q, x, v;
    set<int> s;
    cin>>q;
    while(q--)
    {
        cin>>x>>v;

        if(x==1)
        {
            s.insert(v);
        }

        else if(x==2) s.erase(v);

        else
        {
            if(s.find(v)==s.end()) cout<<"No"<<endl;

            else cout<<"Yes"<<endl;
        }
    }

    return 0;
}


