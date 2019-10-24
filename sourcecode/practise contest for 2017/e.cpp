#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, a, ar[101][101];
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }

    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
            ar[i][j]-=a;
        }

    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ar[i][j];
            if(j!=n-1) cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}


