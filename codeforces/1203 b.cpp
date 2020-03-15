#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;
 int n;
  int ar[3000];

int fnd(int x)
{
    for(int i=0;i<n;i++) if(ar[i]==x) return i;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {

        cin>>n;

        for(int i=1;i<=4*n;i++)
            cin>>ar[i];

        sort(ar+1, ar+4*n+1);

        int br[2*n+10];
        int f=0;

        for(int i=2;i<=4*n;i+=2)
        {
            if(ar[i]==ar[i-1]) br[i/2]=ar[i];
            else{
//                cout<<"NO"<<endl;
//                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }

        int fc=br[1]*br[2*n];

        for(int i=2;i<=n;i++)
        {
            if(fc!=br[i]*br[2*n-i+1])
            {
//                cout<<i<<endl;
//                cout<<br[i]<<" "<<br[2*n-i+1]<<endl;
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else cout<<"YES"<<endl;


    }

    return 0;
}


