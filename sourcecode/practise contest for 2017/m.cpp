#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, ch, a;

    scanf("%d%d", &m, &n);

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &a);
            printf("%c", 96+a);
            if(j!=n) printf(" ");


        }
        puts("");

    }

    return 0;
}




