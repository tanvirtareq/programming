#include<bits/stdc++.h>
#define m 10000007

typedef unsigned long long ull;
typedef long long int lld;

using namespace std;

lld ar[10000];

ull a, b, c, d, e, f;
ull fn( ull n ) {
    if( n == 0 ) return a%m;
    if( n == 1 ) return b%m;
    if( n == 2 ) return c%m;
    if( n == 3 ) return d%m;
    if( n == 4 ) return e%m;
    if( n == 5 ) return f%m;
    if(ar[n]!=-1) return ar[n]%m;
    else{
    ar[n]=( fn(n-1)%m + fn(n-2)%m + fn(n-3)%m + fn(n-4)%m + fn(n-5)%m + fn(n-6)%m );
    return ar[n]%m;
    }
}
int main() {
    ull n, caseno = 0, cases;
    scanf("%llu", &cases);
    while( cases-- ) {
            memset(ar, -1, sizeof(ar));
        scanf("%llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %llu: %llu\n", ++caseno, fn(n) % m);
    }
    return 0;
}
/**
6

0 1 2 3 4 5 20

3 2 1 5 0 1 9

4 12 9 4 5 6 15

9 8 7 6 5 4 3

3 4 3 2 54 5 4

10000 10000 10000 10000 10000 10000 10000
*/
