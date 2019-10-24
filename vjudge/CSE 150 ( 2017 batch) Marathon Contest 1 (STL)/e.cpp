#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i=0, ar[1010];
    while(1)
    {
    cin>>n;
    i=0;
    int s=0;
    if(n==0) break;
    while(n--)
    {
        cin>>ar[i++];
        s+=ar[i-1];
    }
    sort(ar, ar+i-1);
    s-=ar[i-1];
    if(s==ar[i-1]) cout<<s<<endl;
    else cout<<"no solution"<<endl;

    }

    return 0;
}
