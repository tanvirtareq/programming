#include<bits/stdc++.h>
#define f(n) for(int i=1;i<=n;i++)
#define fr(i, n) for(int i=1;i<=n;i++)
#define pb(a) push_back(a)
#define clrar(a) memset(a, 0, sizeof a)


using namespace std;

int n, m=0;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {


        cin>>n>>m;
        char ar[n+10][m+10];
        int rw[n+10], cl[m+10];

        clrar(rw);
        clrar(cl);
        clrar(ar);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ar[i][j];
                if(ar[i][j]=='.')
                {
                    rw[i]++;
                    cl[j]++;
                }
            }
        }

        int ct=INT_MAX;

        fr(i, n)
        {
            fr(j, m)
            {
                ct=min(ct, rw[i]+cl[j]-(ar[i][j]=='.'));

            }
        }

        cout<<ct<<endl;

    }
    return 0;
}


