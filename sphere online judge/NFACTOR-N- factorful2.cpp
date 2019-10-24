#include<bits/stdc++.h>
#define sz 100
#define sq 10


using namespace std;

int pc[sz];
int nm[sz][11];
int tt[11];
int ult[11][sz];

void seive_prime()
{
    pc[1]=0;
    for(int i=2;i<=sq;i++)
    {
        if(pc[i]==0)
        {
            pc[i]=1;
            for(int j=i+i;j<=sz;j=j+i)
            {
                pc[j]=pc[j]+1;
            }

        }
    }

    for(int i=1;i<=10;i++)
    {
        int x=0;
        for(int j=0;j<=sz;j++)
        {
            if(pc[j]==i)
            {
                x++;
            }
            nm[j][i]=x;
//            cout<<"upto "<<j<<" "<<i<<" has "<<nm[j][i]<<endl;
        }

    }

    return;
}

int main()
{
    seive_prime();

    int t, a, b, n;
    scanf("%d", &t);
    while(t--)
    {
        int f=0;
        scanf("%d%d%d", &a, &b, &n);

//        for(int i=a;i<=b;i++)
//        {
//            if(n==pc[i])
//            {
//                f=f+1;
//            }
//        }

        f=nm[b][n]-nm[a][n];
//        if(nm[b][n]==0&&nm[a][n]==0) f=0;

        cout<<"n upto a="<<nm[a][n]<<endl;
        cout<<"n upto b="<<nm[b][n]<<endl;

        printf("%d\n", f);
    }
    return 0;
}

