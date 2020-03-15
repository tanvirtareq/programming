#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long int lld;

int main()
{
    int n, a[110];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a, a+n);
    int cnt=0;

    int j=0;

    //for(int i=0;i<n;i++)
       // cout<<a[i];

    for(int i=0;i<n/2;i++)
    {
        cnt+=a[j+1]-a[j];
        j+=2;
    }

    cout<<cnt<<endl;

	return 0;
}

