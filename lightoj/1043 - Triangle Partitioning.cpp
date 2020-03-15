#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        double a, x, d;

        scanf("%lf%*lf%*lf%lf", &a, &x);

        cout<<"Case "<<i<<": ";
        printf("%.10lf\n", sqrt(x/(x+1))*a);

    }

    return 0;
}
