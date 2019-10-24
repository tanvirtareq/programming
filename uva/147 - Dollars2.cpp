#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[40000];

//int  coin[11]={0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10, 20, 50, 100};;
//int  coin[11]={5, 10, 20, 50, 100, 200, 500, 1000, 2000, 10000 };
int  coin[11]={10000,5000, 2000, 1000, 500, 200, 100,200, 50, 20, 10, 5};

int cnt(int state,int  make)
{
    cout<<coin[state]<<" "<<make<<endl;
    if(state>10) return 0;
    if(make==0)
        return 1;
    if(coin[state]>make)
    {
        cout<<state<<endl;
       // cout<<make<<endl;
        return cnt(state+1, make);
    }



    if(table[make]!=-1)
        return table[make];

     int x=cnt(state, make-coin[state]);
     int y=cnt(state+1, make);

    table[make]=x+y;

    //cout<<table[state][make]<<endl;

    return table[make];
}


int main()
{
    double make;

    memset(table, -1, sizeof(table));
    while(scanf("%lf", &make)!=EOF)
    {
        double x=make*100;
       // cout<<x<<endl;
        int y=floor(x);
       // cout<<y<<endl;
       // cout<<make<<endl;
       // printf("%lf\n", make);
        if(y==0) return 0;
        printf("%-6.2lf %17d\n",make, cnt(0, y));
    }


	return 0;
}





