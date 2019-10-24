#include<bits/stdc++.h>
#define sz 1000000
#define sq 1000
using namespace std;

bool a[sz+1];

void seive()
{
    for(int i=2;i<=sq;i++)
        if(a[i]==0)
        for(int j=i+i;j<=sz;j=j+i)
        a[j]=1;
    return;

}

int main()
{
    seive();

    int n, x, r;
    cin>>n;
    for(int i=4;i<n;i++)
        if(a[i]==1&&a[n-i]==1)
    {
        cout<<i<<" "<<n-i<<endl;
        break;
    }


    return 0;
}

