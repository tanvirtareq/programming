#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, x, l;
    vector<int> v;
    vector<int> :: iterator lt;
    cin>>n;
    while(n--)
    {
        cin>>x;
        v.push_back(x);

    }
    cin>>q;
    while(q--)
    {
        cin>>x;
        lt=lower_bound(v.begin(), v.end(), x);
        l=lt-v.begin()+1;
        if(v[l-1]==x) cout<<"Yes ";
        else cout<<"No ";
        cout<<l<<endl;

    }

    return 0;
}
