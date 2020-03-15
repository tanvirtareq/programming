#include<bits/stdc++.h>
#define ll long long
#define lu long long unsigned
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define ii pair<int, int>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll r, c;
    cin>>r>>c;
    if(r<=1 and c<=1)
    {
        cout<<0<<endl;
        return 0;
    }

    if(r<=1 or c<=1)
    {
        int k=2;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cout<<k<<" ";
                k++;
            }
            cout<<endl;
        }
        return 0;

    }

    int n=r*c;
//    dbg(r);
//    dbg(c);

    int ar[r+10][c+10];
    for(int i=1;i<=c;i++)
    {
        ar[1][i]=r+i;
    }

    for(int i=2;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            ar[i][j]=i*(ar[1][j]);


        }
    }

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


