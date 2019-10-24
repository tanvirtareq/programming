#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define sci(a) scanf("%d", &a)
#define clrar(a, v) memset(a, v, sizeof a)
typedef long long int ld;

using namespace std;
int m, c;

vector< vector <int> >a;
vector<int>z;

int dp[210][25];

int mx(int i, int b)
{
    if(i>=c)
        return 0;

    if(b>m) return 0;

    if(dp[i][b]!=-1)
        return dp[i][b];

    int x=-2;

    for(int j=0;j<a[i].size();j++)
    {
        if(b+a[i][j]<=m)
        {
            int y=mx(i+1, b+a[i][j]);
            if(y==-2) continue;

            else
                x=max(x, a[i][j]+y);
        }

    }

  //  cout<<m<<endl;

    if(x==-2)
        return -2;
       // cout<<i<<" "<<b<<" "<<x<<endl;

    return dp[i][b]=x;
}


int main()
{
   int t;
   //cin>>t;
   sci(t);
   while(t--)
   {
       clrar(dp, -1);

       a.clear();

       //cin>>m>>c;
       sci(m);
       sci(c);
       for(int i=1;i<=c;i++)
       {
           int x;
//           cin>>x;

            sci(x);
           z.clear();
           while(x--)
           {
               int y;
//               cin>>y;
                sci(y);
               z.push_back(y);
           }
           a.push_back(z);
       }

       int x=mx(0, 0);
       if(x==-2)
        puts("no solution");
       // cout<<"no solution"<<endl;

       else
        printf("%d\n", x);
   }

	return 0;
}
/**
1
75 6
2 13 12
11 43 84 50 4 42 3 77 74 50 39 88
9 18 72 30 37 23 97 64 6 17
11 2 77 24 28 55 5 40 66 95 34 49
17 89 91 51 17 64 100 55 4 80 24 75 9 12 98 5 76 55
13 18 56 50 41 35 4 45 74 69 92 59 69 88
99 11
18 15 27 89 21 30 68 44 56 29 56 5 85 83 59 58 100 66 7

*/



