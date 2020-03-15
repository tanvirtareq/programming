#include<stdio.h>

int main()
{
    int a, s=0;
    while(scanf("%d", &a)==EOF)
    {
        s+=a;

    }
    printf("%d", s);

}
