#include<bits/stdc++.h>
#define sz 100000000
#define sq 10000


using namespace std;

bool pc[sz];

int prime[sz];

void seive_prime()
{
    pc[1]=0;
    for(int i=2;i<=sq;i++)
    {
        pc[i]++;
//        if(pc[i]==0)
            for(int j=i+i;j<=sz;j=j+i)
                pc[j]++;

    }
//    int j=0;
//    for(int i=2;i<=sz;i++)
//        if(pc[i]==0) prime[j++]=i;

    return;
}

int factorfull[sz];

//void facfull()
//{
//    for(int n=1;n<=sz;n++)
//    {
//        int c=0;
////        cout<<n<<endl;
//        for(int i=0;prime[i]<=n;i++)
//        {
//            if(n%prime[i]==0) c++;
//        }
//        factorfull[n]=c;
////        cout<<n<<" "<<c<<endl;
//    }
//
//    return;
//}


int main()
{
    seive_prime();
//    facfull();
    int t, a, b, n, ffull;
    scanf("%d", &t);
    while(t--)
    {
        ffull=0;
        scanf("%d%d%n", &a, &b, &n);

        for(int i=a;i<=b;i++)
        {
            if(n==pc[i]) ffull++;
            cout<<ffull<<endl;
        }

        printf("%d\n", ffull);
    }
    return 0;
}
