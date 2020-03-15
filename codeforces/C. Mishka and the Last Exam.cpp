#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;



int main()
{

    long long int n;
    cin>>n;
    //cout<<n<<endl;
    long long int  ar[n+10], b[n+10];

    for(long long int i=n;i>n/2;i--)
    {
        cin>>ar[i];
    }
    b[n]=ar[n];
    b[1]=0;
    for(long long int i=n-1;i>n/2;i--)
    {
        long long int mn=min(ar[i], ar[i+1]);

        long long int x=b[n-i];
        if(x>ar[i]-mn)
        {
            b[n-i+1]=x;
            b[i]=ar[i]-x;
        }
        else{
            b[i]=mn;
        b[n-i+1]=ar[i]-mn;
        }

    }

    for(long long int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }


	return 0;
}
