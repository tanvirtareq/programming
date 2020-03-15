#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[2010][2010], k, n, r, a[2000];

int maxcap(int i, int u)
{
    if(u>k) return 0;
    if(u==k) return k;

    if(i>n) return u;

    if(table[i][u]!=-1)
        return table[i][u];

    int x=maxcap(i+1, u+a[i]);
    int y=maxcap(i+1, u);

    table[i][u]=max(x, y);

    return table[i][u];

}
int main()
{

    int t;
    scanf("%d", &t);

    while(t--)
    {
        memset(table, -1, sizeof table);
        memset(a, 0, sizeof a);
        scanf("%d%d", &n, &k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &r);
            int s=0;
            while(r--)
            {
                int x;
                scanf("%d", &x);
                s+=x;
            }
            a[i]=s;
        }

        printf("%d\n", maxcap(1, 0));

    }

	return 0;
}

/**
pantera aorta
zero zero
* *

*/







