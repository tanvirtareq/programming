#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,i,j,k,l,t,arr[12345];
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
        k=0;
        l=0;
    for(i=2;i<=n && k==0;i++)
    {
        if(arr[i]<arr[i-1])
        {
            for(j=i+1;j<=n;j++)
            {
                if(arr[j]<arr[j-1])
                    break;
            }
            if(arr[j]<arr[i])
                k=1;
            else if(arr[j-1]<arr[i-1])
                k=1;
            else{
                while(arr[i-1]==arr[i])
                    i--;
                if(k==0)
                {
                    printf("%lld %lld\n",i,j);
                    return 0;
                }
            }
        }
    }
    if(k)
        printf("impossible\n");
    else
        printf("1 1\n");

}
