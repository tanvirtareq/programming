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

    return 0;
}

