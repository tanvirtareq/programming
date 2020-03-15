#include<bits/stdc++.h>

using namespace std;

bool a[20000000];

vector<long long int>twinprime;

void twin_prime()
{
    for(long long int i=2;i<=20000000;i++)
    {
        if(a[i]==0&&a[i+2]==0)
        {
            twinprime.push_back(i);
        }
//
//
    }


}

void seive_prime()
{
    long long int i, j;
    a[1]=1;
    a[0]=1;

    for(i=2;i<=5000;i++)
    {
        for(j=i+i;j<=20000000;j=j+i)
        {
            a[j]=1;

        }


    }



}

int main()
{
    seive_prime();

    twin_prime();

    int n, x, sqrt;

    while(scanf("%lld", &x)!=EOF)
    {
        printf("(%lld, %lld)\n", twinprime[x-1], twinprime[x-1]+2);


    }


    return 0;
}

