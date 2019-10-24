#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, n;

    while(cin>>a)
    {
        int c=0;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=a;j++)
            {
                cin>>n;
                if(i==j) c=c+n;

            }
        }
        cout<<c<<endl;
    }

    return 0;
}


