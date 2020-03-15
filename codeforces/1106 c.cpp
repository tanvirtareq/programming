#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    int ar[n+10];

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];

    }

    sort(ar+1, ar+n);

    int s=0;

    for(int i=1;i<=n/2;i++)
    {
        s+=(ar[i]+ar[n-i+1])*(ar[i]+ar[n-i+1]);

        //cout<<ar[i]<<" "<<ar[n-i+1]<<endl;
    }

    cout<<s<<endl;

    return 0;
}

/**

8 5
8 6 2 1 4 5 7 5
6 3 3 2 6 2 3 2
2 8
1 4
4 7
3 4
6 10


*/
