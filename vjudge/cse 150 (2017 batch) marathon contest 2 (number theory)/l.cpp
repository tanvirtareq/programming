#include<bits/stdc++.h>
#define sz 100000
#define psz 9599
#define m 1000000007
typedef long long int llu;

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        llu n;
        cin>>n;
        int cnt=0;
        for(int j=3;j*j<=n;j++)
        {
            if(n%i==0)
            {
                if(i*i==n) cnt++;
                else cnt=cnt+2;
            }
        }
        cout<<"Case "<<i<<": "<<cnt<<endl;
    }

    return 0;
}

