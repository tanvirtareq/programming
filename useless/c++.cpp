#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            if(j%2==0) printf("#");

            else printf("*");
        }
        puts("");
    }

    return 0;
}
