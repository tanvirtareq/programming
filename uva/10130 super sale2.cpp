#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int table[1010][1010];
int t, n, p[1010], w[1010], g,capv;

int knapsac(int state, int befw)
{
    //cout<<n<<endl;
    int profit1, profit2;

    if(table[state][befw]!=-1)
    {
       // cout<<state<<" "<<befw<<" was saved"<<endl;
        return table[state][befw];
    }
    // cout<<state<<endl;

    if(state==(n+1))
    {
         return 0;
    }


       // cout<<state<<endl;

    if((befw+w[state])>capv)
    {
        profit1=0;

    }
    else
    {
        profit1=p[state]+knapsac(state+1, befw+w[state]);

      //  cout<<p[state]<<"  "<<w[state]<<endl;

        // cout<<" if  take "<<state<<"th product maximum can be "<<profit1<<endl;
    }

    profit2=knapsac(state+1, befw);

    // cout<<" if  do not take "<<state<<"th product maximum can be "<<profit2<<endl;


    table[state][befw]=max(profit1, profit2);

    return table[state][befw];

}

int main()
{



//    cin>>t;

    scanf("%d", &t);
    while(t--)
    {


       // cin>>n;
       scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            //cin>>p[i]>>w[i];
            scanf("%d%d", &p[i], &w[i]);
        }

       // cin>>g;
       scanf("%d", &g);

       int sum=0;

        for(int i=1;i<=g;i++)
        {
            memset(table, -1, sizeof(table));
            //int capv;
            //cin>>capv;
            scanf("%d", &capv);
           // cout<<capv<<endl;

            sum+=knapsac(1, 0);
        }

        cout<<sum<<endl;
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


1
3
72 17
44 23
31 24
1
26

*/



