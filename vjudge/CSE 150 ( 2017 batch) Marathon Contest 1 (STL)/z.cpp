#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, m1, m2, m;
    vector<int> v;

    while(cin>>x)
    {
        v.push_back(x);
        sort(v.begin(),v.end());
        if(v.size()%2!=0)
        {
            m=ceil((float)v.size()/2);
            cout<<v[m-1]<<endl;
        }
        else
        {
            m1=v.size()/2;
            m2=m1+1;
            cout<<(v[m1-1]+v[m2-1])/2<<endl;
        }

    }

    return 0;
}

