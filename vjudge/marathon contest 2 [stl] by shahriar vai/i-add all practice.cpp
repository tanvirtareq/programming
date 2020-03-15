#include<bits/stdc++.h>

using namespace std;


vector<int> v;

void permutation(vector<int>v)
{


}

int main()
{
    int n, x, cost;



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

        permutation(v);
    }

    return 0;

}
