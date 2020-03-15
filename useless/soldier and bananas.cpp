#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, w;

    scanf("%d%d%d", &k, &n,&w);

    int s=w*(w+1)/2;

    int m=s*k;

    int b=m-n;

    if(b<0) b=0;

    printf("%d\n", b);


    return 0;
}
