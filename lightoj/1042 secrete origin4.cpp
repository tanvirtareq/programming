#include<bits/stdc++.h>

using namespace std;


int swp(int n,int i,int j)
{
    n=n^(1<<i-1);
    n=n^(1<<j-1);
//    cout<<"swapd value "<<n<<endl;
    return n;

}

bool is1(int pos , int n)
{
    return n&(1<<(pos-1));
}

int merg(int n, int c, int i)
{

    for(int j=1;j<i;j++)
    {
        if(is1(j, n)) n=n^(1<<(j-1));
    }

    for(int j=1;j<=c;j++)
    {
        n=n^(1<<(j-1));
    }
    return n;

}

int answ(int n)
{
    int c=0;
    for(int i=1;i<=32;i++)
    {
        if(is1(i, n))
        {
            if(!is1(i+1, n))
            {
                n=swp(n, i, i+1);
                n=merg(n, c, i);
                return n;
            }
//            {
//                for(int j=1;j<i;j++)
//                {
//                    if(!is1(j, n))
//                    {
//                        n=swp(n, i, j);
//                        c=1;
//                        break;
//                    }
//
//                }
//            }
            c++;
        }
    }
    return n;

}

int main()
{

    int t;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n, b1n, ans;
        cin>>n;

        ans=answ(n);

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}


