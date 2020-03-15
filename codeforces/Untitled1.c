#include<stdio.h>
#include<stdlib.h>

void print(int ar[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d  ", ar[i]);
    }
    puts("\n");
}

void ascending(const int *p,const int *q)
{
    int *l, *r;
    int res;
    l=p;
    r=q;

    res=(*l-*r);
    return (*l-*r);
}

typedef struct {
char name[10];

int solved;
int penalty ;



}player;

void take(player p[])
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%s%d%d", p[i].name, &p[i].solved, &p[i].penalty);
    }
    return;
}

void print1(player p[])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("\n%s\t%d\t%d", p[i].name, p[i].solved, p[i].penalty);
    }
    puts("\n");
    return;
}

int rank(const player *p,const  player *q)
{
    player *l, *r;
    l=p;
    r=q;
    int res;

    int a, b;
    a=l->solved;


    if(l->solved==r->solved)
    {
        res=l->penalty-r->penalty;
        return res;

    }
    else
    {
        res=r->solved-l->solved;
        return res;
    }

}

void take_name(char a[][10])
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%s", a[i]);
    }
    puts("\n");
    return;

}


void print_name(char a[][10])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s\n", a[i]);
    }
    puts("\n");
    return;

}

int srt(char *p[],char *q[])
{
    char *l[10], *r[10];
    l=p;
    r=q;

    int res;
    res=strcmp(*l[10],*r[10]);
    return res;

}

int main()
{
    char ar[5][10];
    take_name(ar);

    print_name(ar);

    qsort(ar, 5, 10*sizeof(char), srt);

    print_name(ar);

    return 0;
}
/*
tareq
3
123
tanvir
2
345
aref
3
124
suhan
4
145
rahman
2
456
*/
