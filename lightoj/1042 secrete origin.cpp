#include<bits/stdc++.h>

using namespace std;

vector<int> bitpat(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n&1);
        n=n>>1;
    }
    return v;

}

int deci(vector<int> v)
{
    int d=0, b=1;
    int sz=v.size();

    for(int i=v.size()-1;i>=0;i--)
    {
        d=d+b*v[i];
        b=b*2;
    }
    return d;

}

int main()
{
    int t;

//    cout<<t;

//    cout<<popcount(536870912)<<endl;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        unsigned long long n, b1n, ans;
        cin>>n;

        vector<int>v;

        v=bitpat(n);

        next_permutation(v.end(), v.begin());

        ans=deci(v);

        for(int i=0;i<v.size();i++)
            cout<<v[i]<<endl;

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}

/** 1
536870912
*/


