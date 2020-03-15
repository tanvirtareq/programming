#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define sci(a) scanf("%d", &a)
#define clrar(a, v) memset(a, v, sizeof a)
typedef long long int ld;

using namespace std;

int n, a[1010], cap[1010], dp[2010][3030];
string x;

int mx(int i, int j)
{
    if(i==j)
        return 0;

    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int r3=INT_MAX;

    if(x[i]==x[j])
        r3=mx(i+1, j-1);

    int r1=1+mx(i+1, j);
    int r2=1+mx(i, j-1);

    int mx1=min(r1, r2);
    int mx2=min(r3, mx1);

    int r4=min(mx2, 1+mx(i, j-1));
    int r5=min(r4, 1+mx(i+1, j));

    int r6=min(r5, 1+mx(i+1, j-1));

    return dp[i][j]=r6;

}


int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int k=1;k<=t;k++)
    {
        clrar(dp, -1);

        getline(cin, x);

        if(x.empty())
        {
            cout<<0<<endl;
            continue;
        }

        int i=0;
        int l=x.size();
        int j=l-1;

        cout<<"Case "<<k<<": "<<mx(i, j)<<endl;

    }

	return 0;
}

/**
12
baabthbesafg
*/



