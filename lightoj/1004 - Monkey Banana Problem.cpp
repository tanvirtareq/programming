#include<bits/stdc++.h>

using namespace std;

int ar[220][110], d[220][110];
int t, n;

int dp(int r, int c)
{

    cout<<ar[r][c]<<endl;

    if(r>=2*n) return 0;

    int q1=0, q2=0, q3=0;

//    q1=q2=ar[r][c];

//    cout<<q1<<endl;

    if(d[n][c]!=-1) return d[r][c];

    int mx=0;

    if(r<n)
    {
        q1=dp(r+1, c);
        q2=dp(r+1, c+1);

        int x=d[r][c]=ar[r][c]+max(q1, q2);
        cout<<ar[r][c]<<" "<<x<<endl;

        return x;

    }

    else {

    q1=dp(r+1, c);

    if(r==4 and c==1) cout<<"{"<<dp(r+1, c)<<ar[r+1][c]<<"}"<<endl;

    if(c>1) q2=dp(r+1, c-1);

    int x=d[r][c]=ar[r][c]+max(q1, q2);

    cout<<ar[r][c]<<" "<<x<<endl;

    return x;
    }

}

void show(int r, int c)
{
        if(r>2*n) return ;

    int q1=0, q2=0, q3=0;

//    q1=q2=ar[r][c];

    cout<<ar[r][c]<<endl;

//    if(d[n][c]!=-1) return d[r][c];

    int mx=0;

    if(r<n)
    {
        q1=d[r+1][c];
        q2=d[r+1][c+1];

        if(q1>q2) show(r+1, c);
        else show(r+1, c+1);

        return ;

    }

    else {

    q1=dp(r+1, c);

    if(c>1) q2=dp(r+1, c-1);

    if(q1>q2) show(r+1, c);
    else show(r+1, c-1);

    return ;
    }
}

int main()
{


    cin>>t;

    for(int k=1;k<=t;k++)
    {
        cin>>n;
        memset(ar, 0, sizeof ar);
        memset(d, -1, sizeof d);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                cin>>ar[i][j];

        }

        for(int i=n+1;i<2*n;i++)
        {
            for(int j=1;j<=n-(i-n);j++)
                cin>>ar[i][j];
        }

        cout<<endl<<endl;

        cout<<"Case "<<k<<": "<<dp(1, 1)<<endl;
        show(1, 1);



    }

    return 0;
}

/**

2

4

7

6 4

2 5 10

9 8 12 2

2 12 7

8 2

10

2

1

2 3

1

*/
