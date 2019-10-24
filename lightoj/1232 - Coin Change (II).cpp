#include<bits/stdc++.h>
//#define m 100000007
//#define moduplus(q1, q2) (q1+q2)%m;

using namespace std;

int t, n, k, coin[102], d[102][10002];

int inline dp(int st, int make)
{
//    cout<<st<<" "<<make<<endl;

    if(make-coin[st]==0) return 1;

    if(make<coin[st]) return 0;

    if(st>n) return 0;

    if(make<0) return 0;

    if(d[st][make]!=-1) return d[st][make];

    int q1=0, q3=0;


    q1=dp(st, make-coin[st]);

//    q2=dp(st+1, make-coin[st]);
    q3=dp(st+1, make);

    return d[st][make]=(q1+q3)%100000007;

}

void prnt()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
            cout<<d[i][j]<<" | ";

        cout<<endl;
    }

}

int main()
{
//    cin>>t;

//    int x[200]={};
//    cout<<x[2]<<endl;

    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
//        cin>>n>>k;
        scanf("%d%d",&n, &k);

//        memset(coin, 0, sizeof coin);
        memset(d, -1, sizeof d);

        for(int j=1;j<=n;j++)
        {
//            cin>>coin[j];
            scanf("%d", &coin[j]);
        }

//        sort(coin+1, coin+n);

//        cout<<"Case "<<i<<": "<<dp(1, k)<<endl;
        printf("Case %d: %d\n", i, dp(1, k));

//        cout<<d[1][k]<<endl;

        prnt();

    }


    return 0;


}

/**

2

3 5

1 2 5

4 20

1 2 3 4

*/
