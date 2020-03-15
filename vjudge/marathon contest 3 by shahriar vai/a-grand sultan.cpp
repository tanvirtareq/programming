#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x=1;
    scanf("%d", &n);

    int a[n+1][n+1];

        int r=1;
        int c=1;
        int trace=1;
        for(int j=2;j<=2*n;j++)
        {
            c=j-trace;
            if(c>n)
            {
                trace++;
                c=j-trace;
            }

            r=trace;

            while(c>=trace)
            {
                a[r][c]=x;
                x++;
                r++;
                c--;
            }
            trace=c+1;
        }

        for(int p=1;p<=n;p++)
        {
            for(int q=n;q>=1;q--)
                printf("%d ", a[p][q]);

            puts("");
        }

    return 0;
}

