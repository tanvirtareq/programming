#include<stdio.h>

void print(int ar[][10], int n)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s\n", ar[i]);
    }
    puts("\n\n\n");
    return;
}

void take(int ar[][10], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%s", ar[i]);
    }
    puts("\n\n\n");
    return;
}

int comparetor(const char p[],const char q[])
{
    return p-q;

}

int main()
{
    char ar[5][10];
    take(ar, 5);

    qsort((void*)ar, 5, sizeof(int), comparetor);

    print(ar, 5);

    return 0;
}
