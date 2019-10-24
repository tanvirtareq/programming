#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if((100000000)%n!=0) puts("Yes");
        else puts("No");
    }
    return 0;
}
