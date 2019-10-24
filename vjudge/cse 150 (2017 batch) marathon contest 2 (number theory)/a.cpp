#include<bits/stdc++.h>
#define sz 1000000

using namespace std;
double a[sz+1];

void all_log()
{
    a[0]=0;
    for(int i=1;i<=sz;i++)
    {
        a[i]=a[i-1]+log(i);
//        cout<<a[i]<<endl;
    }


    return;

}

int main()
{
    all_log();
   int t, n, b;
   double x, y;

   scanf("%d", &t);
   for(int i=1;i<=t;i++)
   {
       x=0;
       scanf("%d%d", &n, &b);
//       while(n--)
//       {
//          x=x+log(n+1);
//       }
        x=a[n];
       y=x/log(b);
       int ans=floor(y)+1;
       printf("Case %d: %d\n", i, ans);

   }

    return 0;
}
