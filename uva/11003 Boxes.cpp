#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define sci(a) scanf("%d", &a)
#define clrar(a, v) memset(a, v, sizeof a)
typedef long long int ld;

using namespace std;

int n, w[1010], cap[1010], dp[1010][3030];

int mx(int i, int cp)
{
    if(i>n) return 0;
    if(cp==INT_MAX)
    {
        int x=1+mx(i+1, cap[i]);
        int y=mx(i+1, cp);

        return max(x, y);
    }
;

    if(dp[i][cp]!=-1)
        return dp[i][cp];

    int x;
    if(w[i]>cp)
        x=0;
    else x=1+mx(i+1, min(cap[i], cp-w[i]));

    int y=mx(i+1, cp);

    return dp[i][cp]=max(x, y);

}


int main()
{
    while(cin>>n)
    {
        clrar(dp, -1);
        if (n==0) return 0;

        for(int i=1;i<=n;i++)
            cin>>w[i]>>cap[i];

        cout<<mx(1, INT_MAX)<<endl;
    }

	return 0;
}

