#include<bits/stdc++.h>

using namespace std;

void read_array(int a[], int n)
{
    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++) scanf("%d", a[i][j]);

    return;

}

int main()
{
    int n, x=1;
    scanf("%d", &n);

    int a[110][110];

//    read_array(a, n);

    for(int p=1;p<=n;p++)
    {
        for(int q=1;q<=n;q++)
        {
            scanf("%d", &a[p][q]);
        }

    }

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
                printf("%d ", a[c][r]);
                r++;
                c--;
            }
            trace=c+1;
        }

    return 0;
}


