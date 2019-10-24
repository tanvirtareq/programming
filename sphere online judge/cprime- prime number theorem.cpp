#include<bits/stdc++.h>

using namespace std;

#define sq 10000
#define sz 100000000

bool ar[100000010];

map<int, int> mp;
vector<int>v;

void seive()
{
    ar[1]=1;
    mp[1]=0;
    for(int i=2;i<=sq;i++)
    {
        if(ar[i]==0)
        {
            v.push_back(i);
            for(int j=i+i;j<=sz;j=j+i)
            {
                ar[j]=1;
            }
        }
        mp[i]=v.size();
    }
    for(int i=i;i<=sz;i++)
    {
        if(ar[i]==0) v.push_back(i);

        mp[i]=v.size();
    }
    return ;

}

int main()
{
    seive();

    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;

        float er=abs(mp[n]-(float)n/log(n));
//        er=er/mp[n]*100;
        float err=er/mp[n];
        printf("%.1f\n", err*100);
    }

    return 0;
}
