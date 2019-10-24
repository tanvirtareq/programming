#include<stdio.h>
#include<math.h>

int num[1000], prime[1000], cnt;

void seive()
{
    int n, i, j;
    n=sqrt(1000);
    num[1]=1;

    for(i=2;i<=1000;i++)
    {
        if(num[i]==0)
        {
            for(j=2*i;j<=n;j=j+i)
            {
                num[j]=1;
            }
        }
    }
    return;
}
void print()
{


}

int main()
{
    seive();
    print();

    return 0;
}
