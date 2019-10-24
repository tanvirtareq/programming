#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[5][7490];

int coin[5]={1, 5, 10, 25, 50}, make;

int cnt(int state,int befc)
{
    if(make==0)
        return 1;

    if(state>4)
        return 0;
   // cout<<coin[state]<<" "<<befc<<"{"<<endl;

   if(table[state][befc]!=-1)
   {
       //cout<<state<<"  "<<befc<<" "<<table[state][befc]<<endl;
       return table[state][befc];
   }

    if(befc+coin[state]==make)
        return 1;



    else if(befc+coin[state]>make )
    {
        return 0;
    }
    int x=cnt(state, befc+coin[state]);

   // int y=cnt(state+1, befc+coin[state]);
    int z=cnt(state+1, befc);

     //cout<<coin[state]<<" "<<befc<<"{"<<endl;

   // cout<<x<<" "<<" "<<z<<endl;

   // cout<<"}"<<endl;

   table[state][befc]=x+z;

    return table[state][befc];

}


int main()
{

    while(scanf("%d", &make))
    {
        memset(table, -1, sizeof(table));

        printf("%d\n", cnt(0, 0));
    }


	return 0;
}



