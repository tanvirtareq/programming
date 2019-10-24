#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m1, m2, x, t;
    vector<int> v;

    cin>>n;
    t=n;
    while(t--)
    {
        cin>>x;
        v.push_back(x);
    }
    m1=0;

    for(t=0;t<n;t++)
    {
        if(v[m1]>v[t]) m1=t;
    }
    if(m1==0) m2=1;
    else m2=0;

    for(t=0;t<n;t++)
        if(v[m2]>v[t]) m2=t;



    return 0;
}
