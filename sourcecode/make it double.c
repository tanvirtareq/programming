#include<stdio.h>
int main()
{
    char a[1000];

    while(scanf("%s", a)!=EOF)
    {
        printf("%s%s\n", a, a);
    }

    return 0;
}
