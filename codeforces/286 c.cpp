#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    int k=min(n, m)+1;
    cout<<k<<endl;
    int i=0;
    int j=m;
    while(k--)
    {
        cout<<i<<" "<<j<<endl;
        i++;
        j--;
    }
    return 0;
}


