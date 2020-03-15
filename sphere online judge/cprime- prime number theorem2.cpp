#include<bits/stdc++.h>

using namespace std;

#define sq 10000
#define sz 100000000

bool ar[100000010];
int arps[100000010];
int arp[100000010];
int s=0;

//map<int, int> mp;
//vector<int>v;

void seive()
{
    ar[1]=1;
    arps[1]=s;
    for(int i=2;i<=sz;i++)
    {
        if(ar[i]==0)
        {
            arp[++s]=i;

            if(i<=sq)
            for(int j=i+i;j<=sz;j=j+i)
            {
                ar[j]=1;
            }
        }
        arps[i]=s;
    }
    return;

}

int main()
{
    seive();

    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;

        float er=abs(arps[n]-(float)n/log(n));
//        er=er/mp[n]*100;
        float err=er/arps[n];
        printf("%.1f\n", err*100);
    }

    return 0;
}
