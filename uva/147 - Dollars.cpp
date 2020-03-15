#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

long long int table[11][40010];

//int  coin[11]={0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10, 20, 50, 100};;
int  coin[11]={5, 10, 20, 50, 100, 200, 500, 1000, 2000,5000,  10000 };

long long int cnt(int state,int  make)
{
    //cout<<coin[state]<<" "<<make<<endl;
    if(state>10) return 0;
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
    double make;

    memset(table, -1, sizeof(table));
    while(scanf("%lf", &make))
    {
        double x=make*100+1e-7;
       // cout<<x<<endl;
        int y=floor(x);
       // cout<<y<<endl;
       // cout<<make<<endl;
       // printf("%lf\n", make);
        if(y==0) return 0;

       // cout<<y<<endl;
        printf("%6.2lf%17lld\n",make, cnt(0, y));
    }


	return 0;
}
