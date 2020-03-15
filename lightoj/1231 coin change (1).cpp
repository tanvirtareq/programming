#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

long long int table[55][1010];

long long int cv[55], n, k;

long long cn[55];


long long int cnt(long long int state,long long int  k)
{
    cout<<"state  "<<state<<endl;
    cout<<" we have "<<cv[state]<<" tk have to make "<<k<<"  have "<<cn[state]<<" coin"<<endl;

    if(state>n+1) return 0;
    if(k==0)
    {
        cout<<"ret"<<endl;
        return 1;
    }
    if(cv[state]>k or cn[state]<0)
    {
       // cout<<make<<endl;
        return 0;
    }



//    if(table[state][k]!=-1)
//        return table[state][k];

    long long int x;

    if(cn[state]!=0)
    {

        cn[state]--;

        x=cnt(state, k-cv[state]);
        cn[state]++;
    }
    else
        x=0;

    long long int y=cnt(state+1, k);

    table[state][k]=x+y;

    cout<<table[state][k]<<endl;


    return table[state][k];
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
        cout<<cv[1]<<endl;

        printf("Case %d: %lld\n",i, cnt(1, k));
    }


	return 0;
}

/**

2

3 5

1 2 5 3 2 1

4 20

1 2 3 4 8 4 2 1

*/





