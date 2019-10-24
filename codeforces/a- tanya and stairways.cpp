#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, p=0, l;
    vector<int>v;

    cin>>n;

    while(n--)
    {
        cin>>a;
        if(p>=a)
        {
            v.push_back(p);
        }
        p=a;

    }
    v.push_back(p);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
