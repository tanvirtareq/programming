#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define m 100000007

using namespace std;

 int table[55][1010][25];

int cv[55], n, k;

int cn[55];


 int cnt(int state,int  k, int amount)
{
////    cout<<"state  "<<state<<endl;
//    cout<<" we have "<<cv[state]<<" tk have to make "<<k<<"  have "<<cn[state]<<" coin"<<endl;

    if(state>=n+1) return 0;
    if(k==0)
    {
//        cout<<"ret"<<endl;
        return 1;
    }

    if(table[state][k][amount]!=-1)
        return table[state][k][amount];

     int x;

    if(cn[state]!=0 and cv[state]<=k and cn[state]>0 )
    {

        cn[state]--;

        x=cnt(state, k-cv[state],cn[state])%m;
        cn[state]++;
    }
    else
        x=0;

     int y;
//    if(cv[state]>k)
//    {
//       // cout<<make<<endl;
//        return 0;
//    }



    y=cnt(state+1, k, cn[state+1])%m;

    table[state][k][amount]=(x+y)%m;

//    cout<<table[state][k][amount]<<endl;


    return table[state][k][amount];
}


int main()
{

    int t;
    scanf("%d", &t);


    for(int i=1;i<=t;i++)
    {
        memset(table, -1, sizeof(table));
        memset(cv, 0, sizeof(cv));
        memset(cn, 0, sizeof(cn));

        scanf("%d%d", &n, &k);

        for(int j=1;j<=n;j++)
        {
            scanf("%d", &cv[j]);
        }

        for(int j=1;j<=n;j++)
        {
            scanf("%d", &cn[j]);
        }
       // cout<<cv[1]<<endl;

        printf("Case %d: %lld\n",i, cnt(1, k, cn[1])%m);
    }


	return 0;
}

/**

2

3 5

1 2 5 3 2 1

4 20

1 2 3 4 8 4 2 1

6 362
54 38 92 23 91 51 14 17 20 16 20 4

*/





