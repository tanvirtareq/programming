#include<bits/stdc++.h>

using namespace std;

//int dp[1000100][1000100];

int w(int n,int k)
{
    if(n==1) return 1;

//    if(dp[n][k]!=0) return dp[n][k];

    return (w(n-1, k)+k-1)%n+1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    while(cin>>n>>k)
    {
        if(n==0 and k==0) break;

        cout<<n<<" "<<k<<" "<<w(n, k)<<endl;

    }

}
