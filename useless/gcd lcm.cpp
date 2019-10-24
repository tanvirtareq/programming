#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned g, l, a, b, i ,p, j, t;

    scanf("%llu", &t);

    while(t--)
    {
        scanf("%llu%llu", &g, &l);

        long long unsigned temp;

        if(l%g!=0)
        {
            printf("-1\n");

        }

        else{
                temp=l/g;

                printf("%llu %llu\n", g, temp*g );

            }





        }

}

