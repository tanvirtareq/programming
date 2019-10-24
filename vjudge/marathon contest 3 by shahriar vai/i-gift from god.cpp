#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n;
    int d[n+1];
    for(int i=2;i<=n;i++)
    {
        cin>>d[i];
    }

    cin>>a>>b;
    int s=0;

    for(int i=a+1;i<=b;i++) s=s+d[i];

    cout<<s<<endl;


}
