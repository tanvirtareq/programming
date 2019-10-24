#include<bits/stdc++.h>
#define m 10000007

typedef unsigned long long ull;

using namespace std;

ull ar[10000];

ull a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}

ull fu(long long int n)
{
    ar[0]=a%m;
    ar[1]=b%m;
    ar[2]=c%m;
    ar[3]=d%m;
    ar[4]=e%m;
    ar[5]=f%m;

    for(ull i=6;i<=n;i++)
    {
        ar[i]=(ar[i-1]%m+ar[i-2]%m+ar[i-3]%m+ar[i-4]%m+ar[i-5]%m+ar[i-6]%m)%m;
    }

    return ar[n];
}

int main() {

    ull n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &n);

        printf("Case %llu: %llu\n", ++caseno, fu(n) % m);
    }
    return 0;
}
/**
5

0 1 2 3 4 5 20

3 2 1 5 0 1 9

4 12 9 4 5 6 15

9 8 7 6 5 4 3

3 4 3 2 54 5 4


*/

