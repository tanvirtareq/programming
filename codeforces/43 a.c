#include<stdio.h>
#include<string.h>

int main()
{
    int n, t1=0, t2=0;
    char s1[1000];
    char s2[1000];
    char x[1000];
    scanf("%d", &n);

//    printf("%d", strcmp("a", "a"));

    scanf("%*c%s", s1);
    t1=1;
    n--;
    while(n--)
    {
        scanf("%*c%s", x);
        if(strcmp(s1, x)==0)
        {
            t1++;
//            puts("te");
        }
        else
        {
            strcpy(s2, x);
//            printf("%s\n", s2);
            t2++;
        }

    }
    if(t1>t2) printf("%s", s1);
        else printf("%s", s2);
    return 0;
}
