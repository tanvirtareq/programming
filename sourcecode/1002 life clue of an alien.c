#include<stdio.h>

int func(int r, char a[])
{
    int cnt=0, x;
    while(cnt<8)
    {
        x=r%5;

        switch(x)
        {
        case 1:
            a[cnt]='A';
            break;

        case 2:
            a[cnt]='T';
            break;

        case 3:
            a[cnt]='G';
            break;

        case 4:
            a[cnt]='C';
            break;

        case 0:
            a[cnt]='X';
            break;
        }

        r=r/5;
        cnt++;
    }
    return cnt;

}

void print(char a[],int cnt)
{
    int re,i;
    for(i=7;i>=0;i--)
    {
        printf("%c", a[i]);
    }

    return;
}

int main()
{
    int t, n,r, cnt;
    char a[20];

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &r);

            cnt=func(r, a);
            print(a, cnt);


        }
        puts("");
    }

    return 0;
}
