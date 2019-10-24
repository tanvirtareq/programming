#include<stdio.h>

typedef struct{
char name[20];
int solved;
int penalty;

}player;

void take(player p[])
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%s%d%d", p[i].name, &p[i].solved, &p[i].penalty);

    }
    puts("");
    return;
}

void print(player p[])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s\t%d\t%d\n", p[i].name, p[i].solved, p[i].penalty);
    }
    puts("\n");

    return;
}

int rank(player *p, player *q)
{
    player *l, *r;
    l=p;
    r=q;
    int res;
    if(l->solved==r->solved)
    {
        if(l->penalty==r->penalty)
        {
            res=strcmp(l->name, r->name);
            return res;
        }
        else
        {
            res=l->penalty-r->penalty;
            return res;
        }
    }
    else
    {
        res=r->solved-l->solved;
        return res;
    }

}

int main()
{
    player p[5];
    take(p);
    print(p);
    qsort(p, 5, sizeof(p[0]), rank);
    print(p);
    return 0;

}

/*
tareq 3 126
aref 4 325
tanvir 3 267
suhan 4 267
rahman 3 267
*/
