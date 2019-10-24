#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;

    scanf("%d%d%d", &a, &b, &c);

    int g=__gcd(a, b);

    if(c%g==0) printf("Yes");

    else printf("No");


    return 0;
}
