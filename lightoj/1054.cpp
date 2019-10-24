#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int print(vector<int> v)
{
    int x=0;
    for(int i=0;i<v.size();i++)
    {


        x=(x%mod+v[i]%mod)%mod;
        cout<<v[i]<<endl;
    }

    return x;
}
int main()
{
    vector<int> v;
    int t, n, m;
    cin>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>n>>m;
        v.clear();
        for(int j=1;j<=n;j++)
        {
            if(n%j==0)
            {
                v.push_back(j);
            }
        }
        int x=n;
        for(int j=2;j<=m;j++)
        {
            x=x*n;
            v.push_back(x);
        }

        cout<<"Case "<<i<<": "<<print(v)<<endl;
    }


    return 0;
}
