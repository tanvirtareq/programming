#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n)
{
    static int cnt=0;
    int c;

    cnt++;

    printf("count=%d\n", cnt);

    if(n==0) c= 0;

    else if(n==1) c= 1;

    else c=fibonacci(n-1)+fibonacci(n-2);

    printf("number=%d\n", c);

     return c;


}

int main()
{
    int n=5, a=0;
    int *cnt;
    cnt=&a;

    int nmbr=fibonacci(n);

    printf("number=%d\n", nmbr);


}
