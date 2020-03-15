#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, n, k, max;

    for(i=1;scanf("%d", &n);i++)
    {
        if(n==0) break;

        int h[n];

        max=0;

        for(int j=0;j<n;j++)
        {
            scanf("%d", &h[j]);

            max=max+h[j];

        }

        int avg=max/n;

        k=0;

        for(int j=0;j<n;j++)
        {
            if(h[j]>avg) k=k+h[j]-avg;

        }

        printf("Set #%d\nThe minimum number of moves is %d\n\n", i, k);


    }



    return 0;
}
