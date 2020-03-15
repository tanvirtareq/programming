#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a=10, b=20;


    a^=b^=a^=b;

    printf("%d %d", a, b);

    return 0;
}
