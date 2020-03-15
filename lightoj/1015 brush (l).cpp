#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x, sum;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        sum=0;
        while(n--)
        {
            cin>>x;
            if(x>=0) sum+=x;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}
