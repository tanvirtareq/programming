#include<stdio.h>
#include<stdlib.h>

void take(char a[][20])
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%s", a[i]);
    }
    puts("");
    return;

}

void print(char a[][20])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s\n", a[i]);
    }
    puts("\n");
    return;
}

int comparator(char p[20], char q[20])
{
    int res=strcmp(p, q);
    return res;

}

int main()
{
    char a[5][20];
    take(a);

    qsort(a, 5, 20*sizeof(char), comparator);

    print(a);


    return 0;
}
