#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define sci(a) scanf("%d", &a)
#define clrar(a, v) memset(a, v, sizeof a)
typedef long long int ld;

using namespace std;

int n, a[20], dp[20][30];

map<pair<int, int> , int> mp;

int lis(int stage,int prev)
{
    //cout<<stage<<" "<<prev<<endl;
    if(stage>n) return 0;

//    if(stage==n) return 1;

//    if(dp[stage][prev]!=-1)
//        return dp[stage][prev];

    if(mp[make_pair(stage, prev)]!=0)
        return mp[make_pair(stage, prev)];

    if(prev>=a[stage])
        return mp[make_pair(stage, prev)]=lis(stage+1, prev);

    int x=1+lis(stage+1, a[stage]);
    int y=lis(stage+1, prev);

    return mp[make_pair(stage, prev)]=max(x, y);

}


int main()
{
//    while(1){
  //  clrar(dp, -1);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    cout<<lis(1, -INT_MAX)<<endl;

//    }

	return 0;
}

/**
5
1 4 2 4 3

*/

