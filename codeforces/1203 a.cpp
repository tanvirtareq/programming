#include<bits/stdc++.h>

#define ll long long
#define lu long long unsigned

using namespace std;
 int n;
  int ar[300];

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

        for(int i=1;i<=n;i++)
            cin>>ar[i-1];
        int id=fnd(1);

        if(n==1 and ar[0]==1) cout<<"YES"<<endl;

        else if(ar[(id+1)%n]==2)
        {
            int f=0;
            id=(id+1)%n;
            int j=2;
            while(ar[id]!=1)
            {
               if(ar[id]!=j)
               {
                   f=1;
                   break;
               }
               j++;
               id=(id+1)%n;
            }
            if(f==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        else if(ar[(id-1+n)%n]==2)
        {
            int f=0;
            for(int j=1;j<=n;j++)
            {
                if(ar[id]!=j)
                {
                    f=1;
                    break;
                }
                id=(id-1+n)%n;
            }
            if(f==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;

    }

    return 0;
}

