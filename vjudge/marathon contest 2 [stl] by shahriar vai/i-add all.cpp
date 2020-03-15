#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, x, cost;

    vector<int> v;

    while(cin>>n)
    {
        cost =0;
        if(n==0) break;

        v.clear();

        while(n--)
        {
            cin>>x;

            v.push_back(x);


        }

        while(v.size()>=2)
        {
            sort(v.begin(), v.end());
            v[0]=v[0]+v[1];
            cost=cost+v[0];
            v.erase(v.begin()+1);

        }


        cout<<cost<<endl;


    }


    return 0;
}
