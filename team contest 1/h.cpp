#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    unsigned long long a, ans, e, x;
    cin>>t;
    while(t--)
    {
        double t1, t2;
        cin>>a;
        t1=(double) a/6.0;
        t2=sqrt(t1);
        ans=(unsigned long long ) t2;
        cout<<ans<<endl;
    }


    return 0;
}
