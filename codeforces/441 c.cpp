#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int i=1, j=1;
    while(k>1)
    {
        k--;
        cout<<"2 "<<i<<" "<<j<<" ";
        if(i%2)
        {
            j++;
            if(j>m)
            {
                j=m;
                i++;
            }
        }
        else
        {
            j--;
            if(j<=0)
            {
                j=1;
                i++;
            }
        }
        cout<<i<<" "<<j<<endl;

        if(i%2)
        {
            j++;
            if(j>m)
            {
                j=m;
                i++;
            }
        }
        elseN
        {
            j--;
            if(j<=0)
            {
                j=1;
                i++;
            }
        }
    }

    vector<int> v;
    while(i<=n and j<=m)
    {
        v.push_back(i);
        v.push_back(j);
        if(i%2)
        {
            j++;
            if(j>m)
            {
                j=m;
                i++;
            }
        }
        else
        {
            j--;
            if(j<=0)
            {
                j=1;
                i++;
            }
        }
    }
    cout<<v.size()/2<<" ";
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";

    return 0;
}
