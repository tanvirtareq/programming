#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[101][104][110];

int napsac(int state, int befw,int capv, int n,int w[],int m[], int g )
{
    int profit1, profit2, profit3;

    if(table[state][befw][capv]!=-1)
    {
        return table[state][befw][capv];
    }

    if(state=n+1)
        return 0;

    if(befw+w[state]>m[capv])
    {
        profit1=0;

    }
    else
    {
        profit1=napsac(state+1, befw+w[state], capv, n, w, m, g);
    }

    if(capv==g)
        profit2=0;

    else
    {
        profit2=napsac(state, befw, capv+1, n, w, m, g);
    }

    profit3=napsac(state+1, befw, capv, n, w, m, g);

    int mx1=max(profit1, profit2);



    table[state][befw][capv]=max(mx1, profit3);

    return table[state][befw][capv];

}

int main()
{
    int t, n, p[1010], w[1010], g, m[110];

    cin>>t;
    while(t--)
    {

        memset(table, -1, sizeof(table));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i]>>w[i];
        }

        cin>>g;

        for(int i=1;i<=g;i++)
        {
            cin>>m[i];
        }

        cout<<napsac(1, 0, 1, n, w, m, g)<<endl;
    }

	return 0;
}

/**

2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26

*/


