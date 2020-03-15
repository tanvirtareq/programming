#include<stdio.h>
#include<math.h>

int a[110], prime[100];

void seive_prime()
{
    long long int i, j, rt;
    a[1]=1;
    a[0]=1;

    rt=sqrt(100);

    for(i=2;i<=rt;i++)
    {
        for(j=i+i;j<=100;j=j+i)
        {
            a[j]=1;

        }


    }


    return;


}

int main()
{
    int i, j;

    seive_prime();

    for(i=2;i<=100;i++)
    {
        if(a[i]==0) printf("%d\n", i);
    }

    return 0;
}
/**
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97


2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97


*/
