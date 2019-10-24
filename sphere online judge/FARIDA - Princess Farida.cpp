#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
typedef long long int ld;

using namespace std;

ld dp[10010], n, a[10010];

ld mx(ld i)
{
    //cout<<i<<" "<<n<<endl;
    if(i>n)
        return 0;

   // cout<<dp[i]<<endl;

    if(dp[i]!=-1)
        return dp[i];

    ld x=a[i]+mx(i+2);
    ld y=mx(i+1);

   // cout<<x<<" "<<y<<endl;

    return dp[i]=max(x, y);

}


int main()
{
    ld t;
    cin>>t;
    for(ld i=1;i<=t;i++)
    {
        memset(dp, -1, sizeof dp);
        cin>>n;
        for(ld j=1;j<=n;j++)
        {
            cin>>a[j];
        }

        cout<<"Case "<<i<<": "<<mx(1)<<endl;

    }

	return 0;
}
