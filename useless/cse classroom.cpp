#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#define sz 100
int cnt;

struct team{
    char name[100];
    int solve;
    int penalty;
    team()
    {
        strcpy(name,"team");
        char str[100]="0";
        int n = 0, ind = 4,x=cnt++;

        while(x)
        {
            str[n++] = '0' + x%10;
            x/=10;
        }
        n=(n<=0)?1:n;
        str[n]=0;

        n = strlen(str);
        for (int i = 0; i<n/2; i++)
        {
            char temp = str[i];
            str[i]=str[n-i-1];
            str[n-i-1]=temp;
        }



        for (int i = 0; i<n; i++)
            name[ind++]=str[i];
        name[ind]=0;
    }
}teams[sz];


int comp(const void *a, const void *b)
{
    if(((team *)b)->solve==((team *)a)->solve)
        return ((team *)a)->penalty - ((team *)b)->penalty;
    return ((team *)b)->solve - ((team *)a)->solve;
}



int main()
{
    srand(time(NULL));
    int i;


    for (i = 0; i<sz; i++)
    {
        teams[i].solve = rand()%11;
        if(teams[i].solve==0) teams[i].penalty = 0;
        else teams[i].penalty = rand()+1;
    }
    qsort(teams,sz,sizeof(team),comp);
    for (i = 0; i<sz; i++)
    {
        printf("%s %d %d\n", teams[i].name,teams[i].solve, teams[i].penalty);
    }


    return 0;
}
