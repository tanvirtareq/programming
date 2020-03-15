#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n, k, x;
    cin>>n;
    k=n/2;
    cout<<k<<endl;
    x=(n-2)/2;
    while(x--) cout<<"2 ";

    if(n%2==0) cout<<"2"<<endl;

    if(n%2==1)
    {
        cout<<"3"<<endl;
    }

    return 0;
}
