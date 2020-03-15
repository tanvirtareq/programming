#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

long long int table[5][8000];

int coin[5]={1, 5, 10, 25, 50};

long long int cnt(int state,int  make)
{
    if(state>4) return 0;
    if(make==0)
        return 1;
    if(coin[state]>make)
    {
       // cout<<make<<endl;
        return 0;
    }



    if(table[state][make]!=-1)
        return table[state][make];

    long long int x=cnt(state, make-coin[state]);
    long long int y=cnt(state+1, make);

    table[state][make]=x+y;

    //cout<<table[state][make]<<endl;

    return table[state][make];
}


int main()
{
    int make;

    memset(table, -1, sizeof(table));
    while(scanf("%d", &make)!=EOF)
    {
        printf("%lld\n", cnt(0, make));
    }


	return 0;
}




