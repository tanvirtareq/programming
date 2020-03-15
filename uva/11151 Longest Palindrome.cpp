#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define sci(a) scanf("%d", &a)
#define clrar(a, v) memset(a, v, sizeof a)
typedef long long int ld;

using namespace std;

int n, a[1010], cap[1010], dp[2010][3030];
string x;

int mx(int i, int j, int l)
{
    if(i==j)
        return 0;

    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int r3=INT_MAX;

    if(x[i]==x[j])
        r3=mx(i+1, j-1, l);

    int r1=1+mx(i+1, j, l);
    int r2=1+mx(i, j-1, l);

    int mx1=min(r1, r2);
    int mx2=min(r3, mx1);

    return dp[i][j]=mx2;

}


int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        clrar(dp, -1);
        char ch;

        getline(cin, x);

        if(x.empty())
        {
            cout<<0<<endl;
            continue;
        }

        int i=0;
        int l=x.size();
        int j=l-1;

        cout<<l-mx(i, j, l)<<endl;

    }

	return 0;
}

/**
12
baabthbesafg
*/


