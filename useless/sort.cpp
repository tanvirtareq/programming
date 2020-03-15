#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>a;

    for(int i=0;i<3;i++)
    {
        int b;

        scanf("%d", &b);

        a.push_back(b);


    }

    sort(a.begin(),a.end());

    int max=0;

    int ans=(a[0]+a[1])*a[2];

    if(ans>max) max=ans;

    ans=a[0]+a[1]+a[2];

    if(ans>max) max=ans;

    ans=a[0]*a[1]*a[2];

    if(ans>max) max=ans;


    printf("%d", max);


    return 0;
}
