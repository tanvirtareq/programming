#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(n<=9)
        {
            cout<<n<<endl;
            continue;
        }
        int n1=n-10;
        n=10;
        ll s=(n1/9)*10;
        n1=n1-(n1/9)*9;

        n+=n1;

         while(n>=10)
        {
            n-=9;
            s+=10;
        }
        s+=n;

        cout<<s<<endl;

    }

    return 0;
}

