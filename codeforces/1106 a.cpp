#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, cnt=0;
    char ar[510][510];

    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>ar[i][j];

     for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
        {
            if(ar[i][j]=='X' and
               ar[i-1][j-1]=='X' and
               ar[i-1][j+1]=='X' and
               ar[i+1][j-1]=='X' and
               ar[i+1][j+1]=='X')
                cnt++;
        }

    cout<<cnt<<endl;

    return 0;
}
