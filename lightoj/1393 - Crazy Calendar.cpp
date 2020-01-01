#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);

    for(int in=1;in<=q;in++)
    {
       int r, c, xr=0;
       scanf("%d%d", &r, &c);
       int ar[r+10][c+10];
       for(int i=r-1;i>=0;i--)
       {
           for(int j=c-1;j>=0;j--)
           {
               scanf("%d", &ar[i][j]);
           }
       }

       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if((i+j)%2!=0) xr^=ar[i][j];
           }
       }

       printf("Case %d: ", in);
       if(xr==0) puts("lose");
       else puts("win");
    }
    return 0;
}




