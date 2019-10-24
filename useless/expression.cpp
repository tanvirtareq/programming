#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, ans, max;

    scanf("%d%d%d", &a, &b, &c);

    max=0;

    ans=a+b+c;

    if(max<ans) max=ans;

    ans=a+b*c;

    if(max<ans) max=ans;

    ans=a*b+c;

    if(max<ans) max=ans;

  ans=a*b*c;

    if(max<ans) max=ans;

  ans=(a+b)*c;

    if(max<ans) max=ans;

    ans=a*(b+c);

    if(max<ans) max=ans;


  printf("%d", max);

    return 0;
}
