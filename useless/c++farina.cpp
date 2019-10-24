#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, space=0;
    scanf("%d", &n);

    space=n/2;

    for(int i=1;i<=n ;i+=2)
    {
        for(int k=1;k<=space;k++)
            printf(" ");

        for(int j=1 ;j<=i;j++)
        {
            printf("*");
        }
        puts("");
        space--;
    }

    return 0;
}
