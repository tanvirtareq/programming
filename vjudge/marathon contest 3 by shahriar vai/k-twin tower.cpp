#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;

    vector<int> v;
    cin>>n;
    int tsum=0;
    while(n--)
    {
        cin>>a;
        tsum=tsum+a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int s=0;
    int c=0;

    while(s<=tsum/2)
    {
        c++;
        int tmp=v.size()-1;
        s=s+v[tmp];
        v.erase(v.end()-1);
    }

    cout<<c<<endl;

}

